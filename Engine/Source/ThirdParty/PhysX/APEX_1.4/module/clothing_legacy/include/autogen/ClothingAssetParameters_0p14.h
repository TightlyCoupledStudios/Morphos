// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2015 NVIDIA Corporation. All rights reserved.

// This file was generated by NvParameterized/scripts/GenParameterized.pl


#ifndef HEADER_ClothingAssetParameters_0p14_h
#define HEADER_ClothingAssetParameters_0p14_h

#include "NvParametersTypes.h"

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
#include "nvparameterized/NvParameterized.h"
#include "nvparameterized/NvParameterizedTraits.h"
#include "NvParameters.h"
#include "NvTraitsInternal.h"
#endif

namespace nvidia
{
namespace parameterized
{

#if PX_VC
#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())
#endif

namespace ClothingAssetParameters_0p14NS
{

struct BoneEntry_Type;
struct ActorEntry_Type;
struct BoneSphere_Type;
struct BonePlane_Type;
struct CookedEntry_Type;
struct SimulationParams_Type;

struct REF_DynamicArray1D_Type
{
	NvParameterized::Interface** buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct BoneEntry_DynamicArray1D_Type
{
	BoneEntry_Type* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct ActorEntry_DynamicArray1D_Type
{
	ActorEntry_Type* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct VEC3_DynamicArray1D_Type
{
	physx::PxVec3* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct BoneSphere_DynamicArray1D_Type
{
	BoneSphere_Type* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct U16_DynamicArray1D_Type
{
	uint16_t* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct BonePlane_DynamicArray1D_Type
{
	BonePlane_Type* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct U32_DynamicArray1D_Type
{
	uint32_t* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct CookedEntry_DynamicArray1D_Type
{
	CookedEntry_Type* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct BonePlane_Type
{
	int32_t boneIndex;
	physx::PxVec3 n;
	float d;
};
struct BoneSphere_Type
{
	int32_t boneIndex;
	float radius;
	physx::PxVec3 localPos;
};
struct SimulationParams_Type
{
	uint32_t hierarchicalLevels;
	float thickness;
	float virtualParticleDensity;
	physx::PxVec3 gravityDirection;
	float sleepLinearVelocity;
	bool disableCCD;
	bool untangling;
	bool twowayInteraction;
	float restLengthScale;
};
struct CookedEntry_Type
{
	float scale;
	NvParameterized::Interface* cookedData;
};
struct BoneEntry_Type
{
	int32_t internalIndex;
	int32_t externalIndex;
	uint32_t numMeshReferenced;
	uint32_t numRigidBodiesReferenced;
	int32_t parentIndex;
	physx::PxMat44 bindPose;
	NvParameterized::DummyStringStruct name;
};
struct ActorEntry_Type
{
	int32_t boneIndex;
	uint32_t convexVerticesStart;
	uint32_t convexVerticesCount;
	float capsuleRadius;
	float capsuleHeight;
	physx::PxMat44 localPose;
};

struct ParametersStruct
{

	REF_DynamicArray1D_Type physicalMeshes;
	REF_DynamicArray1D_Type graphicalLods;
	SimulationParams_Type simulation;
	BoneEntry_DynamicArray1D_Type bones;
	uint32_t bonesReferenced;
	uint32_t bonesReferencedByMesh;
	uint32_t rootBoneIndex;
	ActorEntry_DynamicArray1D_Type boneActors;
	VEC3_DynamicArray1D_Type boneVertices;
	BoneSphere_DynamicArray1D_Type boneSpheres;
	U16_DynamicArray1D_Type boneSphereConnections;
	BonePlane_DynamicArray1D_Type bonePlanes;
	U32_DynamicArray1D_Type collisionConvexes;
	CookedEntry_DynamicArray1D_Type cookedData;
	physx::PxBounds3 boundingBox;
	NvParameterized::Interface* materialLibrary;
	uint32_t materialIndex;
	uint32_t interCollisionChannels;
	NvParameterized::DummyStringStruct toolString;

};

static const uint32_t checksum[] = { 0x1095fcd4, 0x7327d8f7, 0xefaa63f8, 0x5bda9add, };

} // namespace ClothingAssetParameters_0p14NS

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
class ClothingAssetParameters_0p14 : public NvParameterized::NvParameters, public ClothingAssetParameters_0p14NS::ParametersStruct
{
public:
	ClothingAssetParameters_0p14(NvParameterized::Traits* traits, void* buf = 0, int32_t* refCount = 0);

	virtual ~ClothingAssetParameters_0p14();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("ClothingAssetParameters");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const uint32_t ClassVersion = ((uint32_t)0 << 16) + (uint32_t)14;

	static uint32_t staticVersion(void)
	{
		return ClassVersion;
	}

	uint32_t version(void) const
	{
		return(staticVersion());
	}

	static const uint32_t ClassAlignment = 8;

	static const uint32_t* staticChecksum(uint32_t& bits)
	{
		bits = 8 * sizeof(ClothingAssetParameters_0p14NS::checksum);
		return ClothingAssetParameters_0p14NS::checksum;
	}

	static void freeParameterDefinitionTable(NvParameterized::Traits* traits);

	const uint32_t* checksum(uint32_t& bits) const
	{
		return staticChecksum(bits);
	}

	const ClothingAssetParameters_0p14NS::ParametersStruct& parameters(void) const
	{
		ClothingAssetParameters_0p14* tmpThis = const_cast<ClothingAssetParameters_0p14*>(this);
		return *(static_cast<ClothingAssetParameters_0p14NS::ParametersStruct*>(tmpThis));
	}

	ClothingAssetParameters_0p14NS::ParametersStruct& parameters(void)
	{
		return *(static_cast<ClothingAssetParameters_0p14NS::ParametersStruct*>(this));
	}

	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle) const;
	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle);

	void initDefaults(void);

protected:

	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void);
	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void) const;


	virtual void getVarPtr(const NvParameterized::Handle& handle, void*& ptr, size_t& offset) const;

private:

	void buildTree(void);
	void initDynamicArrays(void);
	void initStrings(void);
	void initReferences(void);
	void freeDynamicArrays(void);
	void freeStrings(void);
	void freeReferences(void);

	static bool mBuiltFlag;
	static NvParameterized::MutexType mBuiltFlagMutex;
};

class ClothingAssetParameters_0p14Factory : public NvParameterized::Factory
{
	static const char* const vptr;

public:

	virtual void freeParameterDefinitionTable(NvParameterized::Traits* traits)
	{
		ClothingAssetParameters_0p14::freeParameterDefinitionTable(traits);
	}

	virtual NvParameterized::Interface* create(NvParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(ClothingAssetParameters_0p14), ClothingAssetParameters_0p14::ClassAlignment);
		if (!NvParameterized::IsAligned(newPtr, ClothingAssetParameters_0p14::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingAssetParameters_0p14");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(ClothingAssetParameters_0p14)); // always initialize memory allocated to zero for default values
		return NV_PARAM_PLACEMENT_NEW(newPtr, ClothingAssetParameters_0p14)(paramTraits);
	}

	virtual NvParameterized::Interface* finish(NvParameterized::Traits* paramTraits, void* bufObj, void* bufStart, int32_t* refCount)
	{
		if (!NvParameterized::IsAligned(bufObj, ClothingAssetParameters_0p14::ClassAlignment)
		        || !NvParameterized::IsAligned(bufStart, ClothingAssetParameters_0p14::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingAssetParameters_0p14");
			return 0;
		}

		// Init NvParameters-part
		// We used to call empty constructor of ClothingAssetParameters_0p14 here
		// but it may call default constructors of members and spoil the data
		NV_PARAM_PLACEMENT_NEW(bufObj, NvParameterized::NvParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (ClothingAssetParameters_0p14*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (ClothingAssetParameters_0p14::staticClassName());
	}

	virtual uint32_t getVersion()
	{
		return (ClothingAssetParameters_0p14::staticVersion());
	}

	virtual uint32_t getAlignment()
	{
		return (ClothingAssetParameters_0p14::ClassAlignment);
	}

	virtual const uint32_t* getChecksum(uint32_t& bits)
	{
		return (ClothingAssetParameters_0p14::staticChecksum(bits));
	}
};
#endif // NV_PARAMETERIZED_ONLY_LAYOUTS

} // namespace parameterized
} // namespace nvidia

#if PX_VC
#pragma warning(pop)
#endif

#endif
