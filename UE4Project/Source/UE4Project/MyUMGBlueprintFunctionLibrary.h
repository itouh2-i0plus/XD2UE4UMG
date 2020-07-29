// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyUMGBlueprintFunctionLibrary.generated.h"

class UWidgetBlueprint;
/**
 * 
 */
UCLASS()
class UE4PROJECT_API UMyUMGBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    static void CalledFromPython(FString InputString);

    UFUNCTION(BlueprintCallable)
    static UCanvasPanel* GetRootCanvasPanel(UWidgetBlueprint* Widget);

    UFUNCTION(BlueprintCallable)
    static UButton* CreateButton(UWidgetBlueprint* Widget, FString Name);
};
