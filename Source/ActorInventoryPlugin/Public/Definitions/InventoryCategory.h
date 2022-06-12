// Copyright Dominik Pavlicek 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Helpers/InventoryHelpers.h"
#include "UObject/NoExportTypes.h"
#include "InventoryCategory.generated.h"


#define LOCTEXT_NAMESPACE "Inventory Category"

/**
 * 
 */
UCLASS(Blueprintable)
class ACTORINVENTORYPLUGIN_API UInventoryCategory : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory")
	FORCEINLINE FText GetCategoryName() const
	{
		return CategoryData.CategoryName;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory")
	FORCEINLINE UTexture2D* GetCategoryIcon() const
	{
		return CategoryData.CategoryTexture;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory")
	FORCEINLINE UInventoryCategory* GetParentCategory() const
	{
		return CategoryData.ParentCategory;
	}
	
protected:

	// Category Data
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Inventory", meta=(ExposeOnSpawn=true, ShowOnlyInnerProperties))
	FInventoryCategoryData CategoryData;

	// Unique GUID identifier for this record
	UPROPERTY(VisibleAnywhere, Category="Inventory|GUID")
	FGuid Guid = FGuid::NewGuid();

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};

#undef LOCTEXT_NAMESPACE