// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameStateComponent.h"

#include "ControlFlow.h"
#include "ControlFlowManager.h"
#include "ControlFlowNode.h"

UTitleGameStateComponent::UTitleGameStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	UE_LOG(LogTemp, Error, TEXT("FlowStep_TryShowMainScreen"));
}

void UTitleGameStateComponent::BeginPlay()
{
	UE_LOG(LogTemp, Error, TEXT("FlowStep_TryShowMainScreen"));
	Super::BeginPlay();
	OnExperienceLoaded();
	
}

void UTitleGameStateComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

void UTitleGameStateComponent::OnExperienceLoaded()
{
	
	FControlFlow& Flow = FControlFlowStatics::Create(this, TEXT("FrontendFlow"))
		.QueueStep(TEXT("Try Show Main Screen"), this, &ThisClass::FlowStep_TryShowMainScreen);
	Flow.ExecuteFlow();
	/*FControlFlow& Flow = FControlFlowStatics::Create(this, TEXT("FrontendFlow"))
		.QueueStep(TEXT("Wait For User Initialization"), this, &ThisClass::FlowStep_WaitForUserInitialization)
		.QueueStep(TEXT("Try Show Press Start Screen"), this, &ThisClass::FlowStep_TryShowPressStartScreen)
		.QueueStep(TEXT("Try Join Requested Session"), this, &ThisClass::FlowStep_TryJoinRequestedSession)
		.QueueStep(TEXT("Try Show Main Screen"), this, &ThisClass::FlowStep_TryShowMainScreen);

	Flow.ExecuteFlow();

	FrontEndFlow = Flow.AsShared();*/
}

void UTitleGameStateComponent::FlowStep_TryShowMainScreen(FControlFlowNodeRef SubFlow)
{
	UE_LOG(LogTemp, Error, TEXT("FlowStep_TryShowMainScreen"));
}
