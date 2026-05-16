// Fill out your copyright notice in the Description page of Project Settings.


#include "NetPlayerState.h"
#include "NetBaseCharacter.h"
#include "Net/UnrealNetwork.h"

void ANetPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& 
	OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetPlayerState, Data);
	DOREPLIFETIME(ANetPlayerState, PlayerIndex);	
}

void ANetPlayerState::OnRep_PlayerInfo()
{
	ANetBaseCharacter* Char = Cast<ANetBaseCharacter>(GetPawn());
	// If character is available, update it with new info. 
	// Otherwise, wait and try again after a short delay
	if (Char) {
		Char->PlayerInfoReceived = true;
	} else {
		FTimerHandle PlayerInfoUpdateTimer;
		GWorld->GetTimerManager().SetTimer(PlayerInfoUpdateTimer, this,
			&ANetPlayerState::OnRep_PlayerInfo, 0.25f, false);
	}
}