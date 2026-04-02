
#include "AbilityActorEnum.h"
#include "TimerManager.h"

void AAbilityActorEnum::ActivateAbility()
{
    if (CurrentState != EAbilityState::Idle)
        return;

    EnterActiveState();
}

void AAbilityActorEnum::EnterActiveState()
{
    CurrentState = EAbilityState::Active;

    UE_LOG(LogTemp, Warning, TEXT("Ability Active"));

    GetWorldTimerManager().SetTimer(
        ActiveTimer,
        this,
        &AAbilityActorEnum::EnterCooldownState,
        ActiveDuration,
        false
    );
}

void AAbilityActorEnum::EnterCooldownState()
{
    CurrentState = EAbilityState::Cooldown;

    UE_LOG(LogTemp, Warning, TEXT("Cooldown Started"));

    GetWorldTimerManager().SetTimer(
        CooldownTimer,
        this,
        &AAbilityActorEnum::EnterIdleState,
        CooldownDuration,
        false
    );
}

void AAbilityActorEnum::EnterIdleState()
{
    CurrentState = EAbilityState::Idle;

    UE_LOG(LogTemp, Warning, TEXT("Ability Ready"));
}