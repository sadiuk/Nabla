#ifndef __IRR_I_CPU_IMAGE_VIEW_H_INCLUDED__
#define __IRR_I_CPU_IMAGE_VIEW_H_INCLUDED__

#include "irr/asset/IAsset.h"
#include "irr/asset/ICPUImage.h"
#include "irr/asset/IImageView.h"

namespace irr
{
namespace asset
{

class ICPUImageView final : public IImageView<ICPUImage>, public IAsset
{
	public:
		static core::smart_refctd_ptr<ICPUImageView> create(SCreationParams&& params)
		{
			if (!validateCreationParameters(params))
				return nullptr;

			return core::make_smart_refctd_ptr<ICPUImageView>(std::move(params));
		}
		ICPUImageView(SCreationParams&& _params) : IImageView<ICPUImage>(std::move(_params)) {}

		//!
		size_t conservativeSizeEstimate() const override
		{
			return sizeof(SCreationParams);
		}

        core::smart_refctd_ptr<IAsset> clone(uint32_t _depth = ~0u) const override
        {
            auto par = params;
            if (_depth > 0u && par.image)
                par.image = core::smart_refctd_ptr_static_cast<ICPUImage>(par.image->clone(_depth-1u));

            auto cp = core::make_smart_refctd_ptr<ICPUImageView>(std::move(par));
            clone_common(cp.get());

            return cp;
        }

		//!
		void convertToDummyObject(uint32_t referenceLevelsBelowToConvert=0u) override
		{
            convertToDummyObject_common(referenceLevelsBelowToConvert);

			if (referenceLevelsBelowToConvert)
				params.image->convertToDummyObject(referenceLevelsBelowToConvert-1u);
		}

		//!
		_IRR_STATIC_INLINE_CONSTEXPR auto AssetType = ET_IMAGE_VIEW;
		inline IAsset::E_TYPE getAssetType() const override { return AssetType; }

		//!
		const SComponentMapping& getComponents() const { return params.components; }
		SComponentMapping&	getComponents() 
		{ 
			assert(!isImmutable_debug());
			return params.components;
		}

	protected:
		bool canBeRestoredFrom_recurseDAG(const IAsset* _other) const override
		{
			auto* other = static_cast<const ICPUImageView*>(_other);
			const auto& rhs = other->params;

			if (params.flags != rhs.flags)
				return false;
			if (params.format != rhs.format)
				return false;
			if (params.components != rhs.components)
				return false;
			if (params.viewType != rhs.viewType)
				return false;
			if (memcmp(&params.subresourceRange, &rhs.subresourceRange, sizeof(params.subresourceRange)))
				return false;
			if (!canBeRestoredFrom_recurseDAG_call(params.image.get(), rhs.image.get()))
				return false;

			return true;
		}

		void restoreFromDummy_impl(IAsset* _other, uint32_t _levelsBelow) override
		{
			auto* other = static_cast<ICPUImageView*>(_other);

			if (_levelsBelow)
			{
				restoreFromDummy_impl_call(params.image.get(), other->params.image.get(), _levelsBelow - 1u);
			}
		}

		virtual ~ICPUImageView() = default;
};

}
}

#endif