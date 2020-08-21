// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
    virtual void Tick(float DeltaTime) override;
    virtual void BeginPlay() override;

protected:
    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControlledTank() const;

private:
    void AimTowardsCrosshair();
    bool GetSightRayHitLocation(FVector &OutHitLocation) const;
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

    FVector GetReachLineStart() const;
    FVector GetReachLineEnd() const;

    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5f;

    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 0.33333f;

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.0f;
};
