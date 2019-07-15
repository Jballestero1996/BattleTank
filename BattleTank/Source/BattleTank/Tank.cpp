// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Turret.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Controller"));

}

void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{

	TankAimingComponent->setBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UTurret * turretToSet)
{
	TankAimingComponent->setTurretReference(turretToSet);
}

void ATank::AimAt(FVector hitLocation)
{
	
	TankAimingComponent->AimAt(hitLocation, LaunchSpeed);

}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Pew Pew"));
}

