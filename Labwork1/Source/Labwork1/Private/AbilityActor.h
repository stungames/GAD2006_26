#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityActor.generated.h"

UCLASS()
class AAbilityActor : public AActor
{
    GENERATED_BODY()

public:
    virtual void Tick(float DeltaTime) override;

	void StartAbility();
    void ActivateAbility();

private:
	bool bIsActive = false;
	bool bIsOnCooldown = false;
	
	float ActiveTime = 0.0f;
	float CooldownTime = 0.0f;

	float MaxActiveTime = 5.0f;	
	float MaxCooldown = 3.0f;
};