#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CooldownNiceActor.generated.h"

UCLASS()
class ACooldownNiceActor : public AActor
{
    GENERATED_BODY()

public:
    ACooldownNiceActor();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable)
    void ActivateAbility();

private:
    void ResetCooldown();

    FTimerHandle CooldownTimerHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cooldown", meta=(AllowPrivateAccess="true"))
    float CooldownTime = 3.0f;

    bool bIsOnCooldown = false;
};