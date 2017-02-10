// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "SDetailsViewBase.h"
#include "IStructureDetailsView.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class SStructureDetailsView : public SDetailsViewBase, public IStructureDetailsView
{

public:

	SLATE_BEGIN_ARGS(SStructureDetailsView)
		: _DetailsViewArgs()
	{ }
		/** User defined arguments for the details view */
		SLATE_ARGUMENT(FDetailsViewArgs, DetailsViewArgs)

		/** Custom name for the root property node. */
		SLATE_ARGUMENT(FText, CustomName)
	SLATE_END_ARGS()

	/** Destructor. */
	~SStructureDetailsView();

	/** Constructs the property view widgets. */
	void Construct(const FArguments& InArgs);

	UStruct* GetBaseScriptStruct() const;

	virtual bool IsConnected() const override;

	virtual bool DontUpdateValueWhileEditing() const override
	{
		return true;
	}

	virtual bool ContainsMultipleTopLevelObjects() const override
	{
		return false;
	}

public:

	// IStructureDetailsView interface

	virtual IDetailsView& GetDetailsView() override
	{
		return *this;
	}

	virtual TSharedPtr<SWidget> GetWidget() override
	{
		return AsShared();
	}

	virtual void SetStructureData(TSharedPtr<FStructOnScope> InStructData) override;

	virtual FOnFinishedChangingProperties& GetOnFinishedChangingPropertiesDelegate() override
	{
		return OnFinishedChangingProperties();
	}

public:

	// IDetailsView interface

	/** This method is deprecated.  When it is removed, also remove the PRAGMA_DISABLE_DEPRECATION_WARNINGS/PRAGMA_ENABLE_DEPRECATION_WARNINGS at the top and bottom of this file */
	virtual const UClass* GetBaseClass() const override
	{
		return NULL;
	}

	/** This method is deprecated.  When it is removed, also remove the PRAGMA_DISABLE_DEPRECATION_WARNINGS/PRAGMA_ENABLE_DEPRECATION_WARNINGS at the top and bottom of this file */
	virtual UClass* GetBaseClass() override
	{
		return NULL;
	}

	virtual bool IsCategoryHiddenByClass(const TSharedPtr<FComplexPropertyNode>& InRootNode, FName CategoryName) const override
	{
		return false;
	}

	virtual void ForceRefresh() override;
	virtual void MoveScrollOffset(int32 DeltaOffset) override {}
	virtual void AddExternalRootPropertyNode(TSharedRef<FPropertyNode> ExternalRootNode) override {}
	virtual void ClearSearch() override;
public:

	// IDetailsView interface
	virtual const TArray< TWeakObjectPtr<UObject> >& GetSelectedObjects() const override;
	virtual const TArray< TWeakObjectPtr<AActor> >& GetSelectedActors() const override;
	virtual const struct FSelectedActorInfo& GetSelectedActorInfo() const override;

	virtual bool HasClassDefaultObject() const override
	{
		return false;
	}

	virtual void SetOnObjectArrayChanged(FOnObjectArrayChanged OnObjectArrayChangedDelegate) override {}
	virtual void RegisterInstancedCustomPropertyLayout(UStruct* Class, FOnGetDetailCustomizationInstance DetailLayoutDelegate) override;
	virtual void UnregisterInstancedCustomPropertyLayout(UStruct* Class) override;
	virtual void SetObjects(const TArray<UObject*>& InObjects, bool bForceRefresh = false, bool bOverrideLock = false) override {}
	virtual void SetObjects(const TArray< TWeakObjectPtr< UObject > >& InObjects, bool bForceRefresh = false, bool bOverrideLock = false) override {}
	virtual void SetObject(UObject* InObject, bool bForceRefresh = false) override{}
	virtual void RemoveInvalidObjects() override {}
	virtual void SetObjectPackageOverrides(const TMap<TWeakObjectPtr<UObject>, TWeakObjectPtr<UPackage>>& InMapping) override {}
	virtual void SetRootObjectCustomizationInstance(TSharedPtr<IDetailRootObjectCustomization> InRootObjectCustomization) override {}
	virtual TSharedPtr<class IDetailRootObjectCustomization> GetRootObjectCustomization() const override { return nullptr; }

	/* This is required by the base class but there is only ever one root node in a structure details view */
	virtual FRootPropertyNodeList& GetRootNodes() override;

	TSharedPtr<class FComplexPropertyNode> GetRootNode();
	const TSharedPtr<class FComplexPropertyNode> GetRootNode() const;
protected:

	virtual void CustomUpdatePropertyMap(TSharedPtr<FDetailLayoutBuilderImpl>& InDetailLayout) override;

	EVisibility GetPropertyEditingVisibility() const;

private:
	TSharedPtr<class FStructOnScope> StructData;
	FRootPropertyNodeList RootNodes;
	FText CustomName;
};
PRAGMA_ENABLE_DEPRECATION_WARNINGS
