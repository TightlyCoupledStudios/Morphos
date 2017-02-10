// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "AnimGraphNode_BlendSpaceBase.h"
#include "AnimNodes/AnimNode_BlendSpacePlayer.h"
#include "EdGraph/EdGraphNodeUtils.h" // for FNodeTitleTextTable
#include "AnimGraphNode_BlendSpacePlayer.generated.h"

UCLASS(MinimalAPI)
class UAnimGraphNode_BlendSpacePlayer : public UAnimGraphNode_BlendSpaceBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_BlendSpacePlayer Node;

	// UEdGraphNode interface
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	// End of UEdGraphNode interface

	// UAnimGraphNode_Base interface
	virtual void ValidateAnimNodeDuringCompilation(class USkeleton* ForSkeleton, class FCompilerResultsLog& MessageLog) override;
	virtual void BakeDataDuringCompilation(class FCompilerResultsLog& MessageLog) override;
	virtual bool DoesSupportTimeForTransitionGetter() const override;
	virtual UAnimationAsset* GetAnimationAsset() const override;
	virtual const TCHAR* GetTimePropertyName() const override;
	virtual UScriptStruct* GetTimePropertyStruct() const override;
	virtual void GetAllAnimationSequencesReferred(TArray<UAnimationAsset*>& AnimationAssets) const override;
	virtual void ReplaceReferredAnimations(const TMap<UAnimationAsset*, UAnimationAsset*>& AnimAssetReplacementMap) override;
	// End of UAnimGraphNode_Base interface

	// UK2Node interface
	virtual void GetContextMenuActions(const FGraphNodeContextMenuBuilder& Context) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FBlueprintNodeSignature GetSignature() const override;
	// End of UK2Node interface

	virtual void SetAnimationAsset(UAnimationAsset* Asset) override;

private:
	/** Helper function for GetNodeTitle */
	FText GetNodeTitleForBlendSpace(ENodeTitleType::Type TitleType, UBlendSpaceBase* InBlendSpace) const;

private:
	/** Constructing FText strings can be costly, so we cache the node's title */
	FNodeTitleTextTable CachedNodeTitles;
};
