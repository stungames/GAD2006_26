
#include "AbilityActor.h"

void AAbilityActor::StartAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Ability Started"));
}

void AAbilityActor::ActivateAbility()
{
    if (bIsOnCooldown)
        return;

    if (!bIsActive)
    {
        bIsActive = true;
        StartAbility();
    }
}

void AAbilityActor::Tick(float DeltaTime)
{
    if (bIsActive)
    {
        ActiveTime += DeltaTime;

        if (ActiveTime >= MaxActiveTime)
        {
            bIsActive = false;
            bIsOnCooldown = true;
        }
    }

    if (bIsOnCooldown)
    {
        CooldownTime += DeltaTime;

        if (CooldownTime >= MaxCooldown)
        {
            bIsOnCooldown = false;
        }
    }
}