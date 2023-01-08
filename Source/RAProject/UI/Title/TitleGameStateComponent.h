// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "ControlFlowNode.h"
#include "TitleGameStateComponent.generated.h"
class UCommonActivatableWidget;
/**
 * 
 */
UCLASS()
class RAPROJECT_API UTitleGameStateComponent : public UGameStateComponent
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, Category = UI)
		TSoftClassPtr<UCommonActivatableWidget> MainScreenClass;
public:
	UTitleGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void OnExperienceLoaded();//(const ULyraExperienceDefinition* Experience);
	void FlowStep_TryShowMainScreen(FControlFlowNodeRef SubFlow);
};
