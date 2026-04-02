#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityActorEnum.generated.h"

UENUM()
enum class EAbilityState : uint8
{
    Idle,
    Active,
    Cooldown
};

UCLASS()
class AAbilityActorEnum : public AActor
{
    GENERATED_BODY()

public:
    void ActivateAbility();

private:
    void EnterActiveState();
    void EnterCooldownState();
    void EnterIdleState();

    EAbilityState CurrentState = EAbilityState::Idle;
    FTimerHandle ActiveTimer;
    FTimerHandle CooldownTimer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(AllowPrivateAccess="true"))
    float ActiveDuration = 5.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability", meta=(AllowPrivateAccess="true"))
	float CooldownDuration = 3.0f;
};