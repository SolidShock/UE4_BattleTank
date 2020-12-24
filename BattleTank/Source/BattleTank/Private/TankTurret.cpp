// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * DegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}