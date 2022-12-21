// Fill out your copyright notice in the Description page of Project Settings.


#include "OverAllUILayout.h"
#include "GameplayTagsManager.h"

void UOverAllUILayout::NativeConstruct()
{
	
	auto gameUITag = UGameplayTagsManager::Get().FindGameplayTagFromPartialString_Slow("UI.Layer.Game");
	auto gameMenuUITag = UGameplayTagsManager::Get().FindGameplayTagFromPartialString_Slow("UI.Layer.GameMenu");
	auto menuUITag = UGameplayTagsManager::Get().FindGameplayTagFromPartialString_Slow("UI.Layer.Menu");
	
	Layers.Add(gameUITag, GameUI_Layout);
	Layers.Add(gameMenuUITag, GameMenu_Layout);
	Layers.Add(menuUITag, Menu_Layout);

	Super::NativeConstruct();
	//
}

void UOverAllUILayout::NativeDestruct()
{
	Super::NativeDestruct();
}
