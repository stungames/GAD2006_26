#include "CooldownNiceActor.h"
#include "TimerManager.h"

ACooldownNiceActor::ACooldownNiceActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACooldownNiceActor::BeginPlay()
{
    Super::BeginPlay();
}

void ACooldownNiceActor::ActivateAbility()
{
    if (bIsOnCooldown)
        return;

    UE_LOG(LogTemp, Warning, TEXT("Ability Activated"));

    bIsOnCooldown = true;

    GetWorldTimerManager().SetTimer(
        CooldownTimerHandle,
        this,
        &ACooldownNiceActor::ResetCooldown,
        CooldownTime,
        false
    );
}

void ACooldownNiceActor::ResetCooldown()
{
    bIsOnCooldown = false;
    UE_LOG(LogTemp, Warning, TEXT("Cooldown finished"));
}