# Copyright (C) 2018-2020 - DevSH Graphics Programming Sp. z O.O.
# This file is part of the "Nabla Engine".
# For conditions of distribution and use, see copyright notice in nabla.h

add_subdirectory(01.HelloWorld EXCLUDE_FROM_ALL)
add_subdirectory(02.ComputeShader EXCLUDE_FROM_ALL)
add_subdirectory(03.GPU_Mesh EXCLUDE_FROM_ALL)
# free space 04
add_subdirectory(05.NablaTutorialExample EXCLUDE_FROM_ALL)
add_subdirectory(06.MeshLoaders EXCLUDE_FROM_ALL)
#add_subdirectory(07.HardwareSkinning EXCLUDE_FROM_ALL)
add_subdirectory(08.HardwareInstancing EXCLUDE_FROM_ALL)
add_subdirectory(09.ColorSpaceTest EXCLUDE_FROM_ALL)
add_subdirectory(10.AllocatorTest EXCLUDE_FROM_ALL)
#add_subdirectory(11.RayCastCollision EXCLUDE_FROM_ALL)
#add_subdirectory(12.Splines EXCLUDE_FROM_ALL)
if (NBL_BUILD_CEGUI)
	#add_subdirectory(13.BRDF_Explorer EXCLUDE_FROM_ALL)
endif()
#add_subdirectory(14.MSAA EXCLUDE_FROM_ALL) # TODO: Ressurect with Sponza or something?
#add_subdirectory(15.LayeredCubeMapShadows EXCLUDE_FROM_ALL) # TODO: Ressurect with Sponza or something?
#add_subdirectory(16.OrderIndependentTransparencyZoo EXCLUDE_FROM_ALL)
if (NBL_BUILD_BULLET)
	#add_subdirectory(17.SimpleBulletIntegration EXCLUDE_FROM_ALL) # Needs example 08 to come back first
endif()
if (NBL_BUILD_MITSUBA_LOADER)
	add_subdirectory(18.MitsubaLoader EXCLUDE_FROM_ALL)
endif()
add_subdirectory(19.SIMDmatrixMultiplication EXCLUDE_FROM_ALL)
add_subdirectory(20.Megatexture EXCLUDE_FROM_ALL)
add_subdirectory(21.DynamicTextureIndexing EXCLUDE_FROM_ALL) # TODO: revive
if (NBL_BUILD_MITSUBA_LOADER AND NBL_BUILD_RADEON_RAYS)
	add_subdirectory(22.RaytracedAO EXCLUDE_FROM_ALL)
endif()
add_subdirectory(23.Autoexposure EXCLUDE_FROM_ALL)
#add_subdirectory(24.BufferSubDataAlignTest EXCLUDE_FROM_ALL) # TODO: @Anastazluk or @Hazardu
#add_subdirectory(25.Blur EXCLUDE_FROM_ALL)
add_subdirectory(26.MultidrawIndirectVSCPUCull EXCLUDE_FROM_ALL)
#add_subdirectory(27.PointCloud EXCLUDE_FROM_ALL)
if (NBL_BUILD_MITSUBA_LOADER AND NBL_BUILD_OPTIX)
	#add_subdirectory(28.OptiXPathTracing EXCLUDE_FROM_ALL)
endif()
add_subdirectory(29.SpecializationConstants EXCLUDE_FROM_ALL)
add_subdirectory(31.SkinningDataBenchmark EXCLUDE_FROM_ALL)
add_subdirectory(32.MultiThreadedRefCounting EXCLUDE_FROM_ALL) # TODO: @Anastazluk make this into example 04
add_subdirectory(33.Draw3DLine EXCLUDE_FROM_ALL)
add_subdirectory(34.LRUCacheUnitTest EXCLUDE_FROM_ALL)
add_subdirectory(35.GeometryCreator EXCLUDE_FROM_ALL)
add_subdirectory(36.CUDAInterop EXCLUDE_FROM_ALL)
add_subdirectory(37.OptiXTriangle EXCLUDE_FROM_ALL)
add_subdirectory(38.EXRSplit EXCLUDE_FROM_ALL)
if (NBL_BUILD_MITSUBA_LOADER AND NBL_BUILD_OPTIX)
	add_subdirectory(39.DenoiserTonemapper EXCLUDE_FROM_ALL)
endif()
add_subdirectory(40.GLITest EXCLUDE_FROM_ALL)
#add_subdirectory(41.VisibilityBuffer EXCLUDE_FROM_ALL) #TODO: waits for SPIRV-Cross issue about barycentrics
add_subdirectory(42.FragmentShaderPathTracer EXCLUDE_FROM_ALL)
add_subdirectory(43.SumAndCDFFilters EXCLUDE_FROM_ALL)
add_subdirectory(44.LevelCurveExtraction EXCLUDE_FROM_ALL)
add_subdirectory(45.BRDFEvalTest EXCLUDE_FROM_ALL)
add_subdirectory(46.SamplingValidation EXCLUDE_FROM_ALL)
add_subdirectory(47.DerivMapTest EXCLUDE_FROM_ALL)
add_subdirectory(48.ArithmeticUnitTest EXCLUDE_FROM_ALL)
add_subdirectory(49.ComputeFFT EXCLUDE_FROM_ALL)

add_subdirectory(51.WavesSimulation EXCLUDE_FROM_ALL)