// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public: 

	ATank* getControlledTank() const;

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AimToCrossHair();
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	bool GetHitLookLocation(FVector hitDirection, FVector & hitLocation);
	bool GetLookDirection(FVector2D screenLocation, FVector & worldDirection);

	UPROPERTY(EditAnywhere)
		float range = 10000000.0f;

	UPROPERTY(EditAnywhere)
		float crosshairXLocation = 0.5f;
		
	UPROPERTY(EditAnywhere)
		float crosshairYLocation = 0.333f;
};
