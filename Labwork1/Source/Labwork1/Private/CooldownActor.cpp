#include "CooldownActor.h"

ACooldownActor::ACooldownActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACooldownActor::BeginPlay()
{
    Super::BeginPlay();
}

void ACooldownActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsOnCooldown)
    {
        CurrentCooldown += DeltaTime;

        if (CurrentCooldown >= CooldownTime)
        {
            bIsOnCooldown = false;
            CurrentCooldown = 0.0f;

            UE_LOG(LogTemp, Warning, TEXT("Cooldown finished"));
        }
    }
}

void ACooldownActor::ActivateAbility()
{
    if (!bIsOnCooldown)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ability Activated"));

        bIsOnCooldown = true;
        CurrentCooldown = 0.0f;
    }
}