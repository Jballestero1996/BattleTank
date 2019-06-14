// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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