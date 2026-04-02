#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CooldownActor.generated.h"

UCLASS()
class ACooldownActor : public AActor
{
    GENERATED_BODY()

public:
    ACooldownActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void ActivateAbility();

private:
    float CooldownTime = 3.0f;
    float CurrentCooldown = 0.0f;
    bool bIsOnCooldown = false;
};