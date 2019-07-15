// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void RotateTurret(float degrees);


private:

	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditAnywhere)
		float MaxRotationDegrees = 360.0f;

	UPROPERTY(EditAnywhere)
		float MinRotationDegrees = 0.0f;

	
};
