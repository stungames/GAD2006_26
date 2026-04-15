// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"
#include "TBPlayerController.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();
}

void AUnitBase::OnUnitClicked(AActor* TouchedActor, FKey ButtonPressed)
{
	if (auto PlayerController = GWorld->GetFirstPlayerController<ATBPlayerController>())
	{
		PlayerController->OnActorClicked(this, ButtonPressed);
	}
}

// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUnitBase::AssignToSlot(AGameSlot* NewSlot)
{
	check(NewSlot && NewSlot->Unit == nullptr);

	if (Slot) Slot->Unit = nullptr;
	Slot = NewSlot;
	Slot->Unit = this;
	SetActorLocation(Slot->GetActorLocation() + StartOffset);
}
