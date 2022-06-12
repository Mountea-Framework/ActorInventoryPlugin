// Copyright Dominik Pavlicek 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Helpers/InventoryHelpers.h"

#include "ActorInventoryItemComponent.generated.h"

UENUM()
enum class EInventoryItemSetup : uint8
{
	EIIS_FromItem		UMETA(DisplayName="From Item"),
	EIIS_FromDataTable	UMETA(DisplayName="From Data Table"),

	EIIS_Default		UMETA(Hidden)
};

class UInventoryItem;

/**
 * Helper Component which defines that Actor is Inventory Item.
 * Usable for Pickups, like Weapons.
 */
UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent), HideCategories=(Collision, AssetUserData, Cooking, ComponentTick, Activation) )
class ACTORINVENTORYPLUGIN_API UActorInventoryItemComponent final : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory")
	FInventoryItemData GetItemDefinition() const;

protected:

	UPROPERTY(EditAnywhere, Category="Inventory")
	EInventoryItemSetup SetupMode = EInventoryItemSetup::EIIS_FromItem;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(EditCondition="SetupMode==EInventoryItemSetup::EIIS_FromItem", EditConditionHides, NoResetToDefault))
	TSubclassOf<UInventoryItem> SourceItem = nullptr;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(EditCondition="SetupMode==EInventoryItemSetup::EIIS_FromDataTable", EditConditionHides, NoResetToDefault, ShowOnlyInnerProperties))
	FDataTableCategoryHandle SourceItemTable;
	
protected:

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
