// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUMGBlueprintFunctionLibrary.h"


#include "Blueprint/WidgetTree.h"
#include "UMGEditor/Public/WidgetBlueprint.h"

void UMyUMGBlueprintFunctionLibrary::CalledFromPython(FString InputString)
{
    UE_LOG(LogTemp, Error, TEXT("%s"), *InputString);
}


UCanvasPanel* UMyUMGBlueprintFunctionLibrary::GetRootCanvasPanel(UWidgetBlueprint* Widget)
{
    if (Widget == nullptr || Widget->WidgetTree == nullptr) return nullptr;
    auto RootCanvas = Cast<UCanvasPanel>(Widget->WidgetTree->RootWidget);
    return RootCanvas;
}

UButton* UMyUMGBlueprintFunctionLibrary::CreateButton(UWidgetBlueprint* Widget, FString Name)
{
    if (Widget == nullptr) return nullptr;
    auto WidgetTree = Widget->WidgetTree;
    if (WidgetTree == nullptr) return nullptr;
    auto Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), *Name);
    return Button;
}
