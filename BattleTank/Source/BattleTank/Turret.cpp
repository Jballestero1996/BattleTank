// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Engine/World.h"

void UTurret::RotateTurret(float degrees) {


	float relativeSpeed = FMath::Clamp<float>(degrees, -1, 1);

	auto elevationChange = relativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto rawNewRotation = RelativeRotation.Yaw + elevationChange;

	SetRelativeRotation(FRotator(0, rawNewRotation, 0));

}

