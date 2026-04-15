// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"

/**
 * 
 */
class CommandMove : public Command
{
public:
	CommandMove(FSGridPosition Src, FSGridPosition Dst);
	~CommandMove();
	virtual void Execute() override;
	virtual void Revert() override;

private:
	FSGridPosition Source, Destination;
	
};
