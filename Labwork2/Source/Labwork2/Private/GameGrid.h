// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSlot.h"
#include "GameGrid.generated.h"

UCLASS()
class AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameGrid();

	virtual void OnConstruction(const FTransform& Transform) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	TArray<UChildActorComponent*> GridActors;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGameSlot> GridClass;

	UPROPERTY(EditAnywhere)
	int NumRows;

	UPROPERTY(EditAnywhere)
	int NumCols;

	AGameSlot* GetSlot(FSGridPosition& Position);
	static AGameSlot* FindSlot(FSGridPosition Position);

private:
	static AGameGrid* GameGrid;
	
};
