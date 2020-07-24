// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"

#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"

void UGameInstanceBase::Join(FString Adress)
{
	if (!ensure(GEngine != nullptr)) return;
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Joing to %s"), *Adress));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerCntroller = World->GetFirstPlayerController();
	if (!ensure(PlayerCntroller != nullptr)) return;
	PlayerCntroller->ClientTravel(Adress, ETravelType::TRAVEL_Absolute);
}