// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandMove.h"

#include "GameGrid.h"

CommandMove::CommandMove(FSGridPosition Src, FSGridPosition Dst) : 
	Source(Src),
	Destination(Dst)
{

}

CommandMove::~CommandMove()
{
}

void CommandMove::Execute()
{
	UE_LOG(LogTemp, Warning, TEXT("Executing MoveCommand..."));
	AGameSlot* SlotA = AGameGrid::FindSlot(Source);
	AGameSlot* SlotB = AGameGrid::FindSlot(Destination);

	AUnitBase* UnitA = SlotA->Unit;
	check(UnitA);
	UnitA->AssignToSlot(SlotB);
	SlotB->SetState(GS_Highlighted);
}

void CommandMove::Revert()
{
	UE_LOG(LogTemp, Warning, TEXT("Reverting MoveCommand..."));
	AGameSlot* SlotA = AGameGrid::FindSlot(Source);
	AGameSlot* SlotB = AGameGrid::FindSlot(Destination);

	AUnitBase* UnitB = SlotB->Unit;
	check(UnitB);
	UnitB->AssignToSlot(SlotA);
	SlotB->SetState(GS_Default);
}
