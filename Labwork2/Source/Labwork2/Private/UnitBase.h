// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitBase.generated.h"

class AGameSlot;

UCLASS()
class AUnitBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnUnitClicked(AActor* TouchedActor, FKey ButtonPressed);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AssignToSlot(AGameSlot* NewSlot);

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure)
	bool IsControlledByThePlayer();

	UPROPERTY(EditAnywhere)
	FVector StartOffset;	

	UPROPERTY(VisibleAnywhere)
	AGameSlot* Slot;
};
