#ifndef __IRR_I_CPU_DESCRIPTOR_SET_LAYOUT_H_INCLUDED__
#define __IRR_I_CPU_DESCRIPTOR_SET_LAYOUT_H_INCLUDED__

#include "irr/asset/IDescriptorSetLayout.h"
#include "irr/asset/IAsset.h"
#include "irr/asset/ICPUSampler.h"

namespace irr
{
namespace asset
{

class ICPUDescriptorSetLayout : public IDescriptorSetLayout<ICPUSampler>, public IAsset
{
	public:
		using IDescriptorSetLayout<ICPUSampler>::IDescriptorSetLayout;

        core::smart_refctd_ptr<IAsset> clone(uint32_t _depth = ~0u) const override
        {
            auto cp = core::make_smart_refctd_ptr<ICPUDescriptorSetLayout>(nullptr, nullptr);
            clone_common(cp.get());

            if (_depth > 0u && m_bindings)
            {
                cp->m_bindings = core::make_refctd_dynamic_array<decltype(m_bindings)>(m_bindings->size());
                cp->m_samplers = m_samplers ? core::make_refctd_dynamic_array<decltype(m_samplers)>(m_samplers->size()) : nullptr;

                for (size_t i = 0ull; i < m_bindings->size(); ++i)
                {
                    (*cp->m_bindings)[i] = (*m_bindings)[i];
                    if ((*cp->m_bindings)[i].samplers)
                        (*cp->m_bindings)[i].samplers = cp->m_samplers->begin() + ((*cp->m_bindings)[i].samplers - m_samplers->begin());
                }
                if (cp->m_samplers)
                {
                    for (size_t i = 0ull; i < m_samplers->size(); ++i)
                        (*cp->m_samplers)[i] = core::smart_refctd_ptr_static_cast<ICPUSampler>((*m_samplers)[i]->clone(_depth - 1u));
                }
            }
            else
            {
                cp->m_bindings = m_bindings;
                cp->m_samplers = m_samplers;
            }

            return cp;
        }

		size_t conservativeSizeEstimate() const override { return m_bindings->size()*sizeof(SBinding)+m_samplers->size()*sizeof(void*); }
		void convertToDummyObject(uint32_t referenceLevelsBelowToConvert=0u) override
		{
            convertToDummyObject_common(referenceLevelsBelowToConvert);

			if (referenceLevelsBelowToConvert)
			{
                --referenceLevelsBelowToConvert;
				if (m_samplers)
				for (auto it=m_samplers->begin(); it!=m_samplers->end(); it++)
					it->get()->convertToDummyObject(referenceLevelsBelowToConvert);
			}
		}

        bool canBeRestoredFrom_recurseDAG(const IAsset* _other) const override
        {
            auto* other = static_cast<const ICPUDescriptorSetLayout*>(_other);
            if (m_bindings->size() != other->m_bindings->size())
                return false;
            if ((!m_samplers) != (!other->m_samplers))
                return false;
            if (m_samplers && m_samplers->size() != other->m_samplers->size())
                return false;
            if (m_samplers)
            for (uint32_t i = 0u; i < m_samplers->size(); ++i)
                if (!(*m_samplers)[i]->canBeRestoredFrom_recurseDAG((*other->m_samplers)[i].get()))
                    return false;

            return true;
        }

        _IRR_STATIC_INLINE_CONSTEXPR auto AssetType = ET_DESCRIPTOR_SET_LAYOUT;
        inline E_TYPE getAssetType() const override { return AssetType; }

        void restoreFromDummy_impl(IAsset* _other, uint32_t _levelsBelow) override
        {
            auto* other = static_cast<ICPUDescriptorSetLayout*>(_other);

            if (!_levelsBelow)
                return;

            --_levelsBelow;
            if (m_samplers)
            for (uint32_t i = 0u; i < m_samplers->size(); ++i)
                (*m_samplers)[i]->restoreFromDummy_impl((*other->m_samplers)[i].get(), _levelsBelow);
        }

	protected:
		virtual ~ICPUDescriptorSetLayout() = default;
};

}
}

#endif