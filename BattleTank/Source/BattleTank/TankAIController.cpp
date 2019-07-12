// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	ATank* controlledTank = GetControlledTank();
	ATank* playerTank = GetPlayerTank(); 

	if (!controlledTank || !playerTank) {

		UE_LOG(LogTemp, Warning, TEXT("Bro"));
	}

	UE_LOG(LogTemp, Warning, TEXT("%s has been controlled by an AI!"), *GetControlledTank()->GetName());

	UE_LOG(LogTemp, Warning, TEXT("%s sees %s, yay!"), *GetControlledTank()->GetName(), *GetPlayerTank()->GetName());
}

ATank * ATankAIController::GetPlayerTank() const
{

	APawn* playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!playerTank) {
		return nullptr;
	}
	return Cast<ATank>(playerTank);
}

ATank* ATankAIController::GetControlledTank() const {


	return Cast<ATank>(GetPawn());

}

void ATankAIController::Tick(float DeltaTime)
{
	if (GetPlayerTank()) {

		//TODO add movement to the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//TODO Fire
	}
	


}



