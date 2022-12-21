// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "OverAllUILayout.generated.h"
class UCommonActivatableWidgetStack;
class UCommonActivatableWidget;
/**
 * 
 */
UCLASS()
class RAPROJECT_API UOverAllUILayout : public UCommonUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		TObjectPtr < UCommonActivatableWidgetStack> GameUI_Layout;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		TObjectPtr < UCommonActivatableWidgetStack> GameMenu_Layout;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		TObjectPtr<UCommonActivatableWidgetStack> Menu_Layout;
	int test;
	UPROPERTY(Transient, meta = (Categories = "UI.Layer"))
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetStack>> Layers;
	//TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layers;

public:
	void NativeConstruct() override;
	void NativeDestruct() override;

	template <typename ActivatableWidgetT = UCommonActivatableWidget>
	ActivatableWidgetT* PushWidgetToLayerStack(FGameplayTag LayerName, UClass* ActivatableWidgetClass, TFunctionRef<void(ActivatableWidgetT&)> InitInstanceFunc)
	{
		static_assert(TIsDerivedFrom<ActivatableWidgetT, UCommonActivatableWidget>::IsDerived, "Only CommonActivatableWidgets can be used here");

		if (UCommonActivatableWidgetStack* Layer = GetLayerWidget(LayerName))
		{
			return Layer->AddWidget<ActivatableWidgetT>(ActivatableWidgetClass, InitInstanceFunc);
		}

		return nullptr;
	}
};
