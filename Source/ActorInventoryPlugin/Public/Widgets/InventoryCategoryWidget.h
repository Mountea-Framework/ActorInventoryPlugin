// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryCategoryWidget.generated.h"

class UInventoryCategory;

/**
 * 
 */
UCLASS()
class ACTORINVENTORYPLUGIN_API UInventoryCategoryWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Inventory")
	FORCEINLINE UInventoryCategory* GetCategoryDefinition() const
	{
		return ParentCategory;
	}

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory", meta=(ExposeOnSpawn=true))
	UInventoryCategory* ParentCategory = nullptr;
	
};
