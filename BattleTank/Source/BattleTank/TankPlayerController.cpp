// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
ATank* ATankPlayerController::getControlledTank() const {

	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	ATank* controlledTank = getControlledTank();
	if (!controlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("Bro"));
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *getControlledTank()->GetName());
}


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimToCrossHair();
}

void ATankPlayerController::AimToCrossHair() {

	if (!getControlledTank()) {

		return;

	}

	FVector hitLocation;

	if (GetSightRayHitLocation(hitLocation)) { //This raytraces


		getControlledTank()->AimAt(hitLocation);

	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) {

	int32 viewPortSizeX, viewPortSizeY; 

	GetViewportSize(viewPortSizeX, viewPortSizeY);

	FVector2D screenLocation = FVector2D(viewPortSizeX * crosshairXLocation, viewPortSizeY * crosshairYLocation);

	FVector worldDirection;

	if (GetLookDirection(screenLocation, worldDirection)) {

		GetHitLookLocation(worldDirection, OutHitLocation);
		
	}

	return true;
}

bool ATankPlayerController::GetHitLookLocation(FVector hitDirection, FVector& hitLocation) {

	FHitResult hitResult;

	auto startLocation = PlayerCameraManager->GetCameraLocation(); 
	auto endLocation = startLocation + (hitDirection * range);

	if (GetWorld()->LineTraceSingleByChannel(
		hitResult,
		startLocation,
		endLocation,
		ECollisionChannel::ECC_Visibility)) {


		hitLocation = hitResult.Location;
		return true;
	}
	else {

		hitLocation = FVector().ZeroVector;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector &worldDirection) {

	FVector cameraWorldLocation;

	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection);

}