// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::Elevate(float degrees) {


	float relativeSpeed = FMath::Clamp<float>(degrees, -1, 1);

	auto elevationChange = relativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;

	float elevation = FMath::Clamp<float>(rawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(elevation, 0, 0));

}
