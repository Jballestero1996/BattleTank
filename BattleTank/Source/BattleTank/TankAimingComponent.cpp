// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Turret.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::setBarrelReference(UTankBarrel * barrelToSet)
{

	barrel = barrelToSet;
}

void UTankAimingComponent::setTurretReference(UTurret * turretToSet)
{
	turret = turretToSet;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector worldSpace, float launchSpeed)
{


	FVector outLaunchVelocity;
	FVector startingLocation = barrel->GetSocketLocation(FName("Projectile"));

	bool aimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		outLaunchVelocity,
		startingLocation,
		worldSpace,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);


	if (aimSolution) {

		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		FString tankName = GetOwner()->GetName();

		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *tankName, *worldSpace.ToString(), *aimDirection.ToString());
		MoveBarrel(aimDirection);
	}
	

}

void UTankAimingComponent::MoveBarrel(FVector aimDirection) {


	FRotator barrelRotation = barrel->GetForwardVector().Rotation();

	FRotator turretRotation = turret->GetForwardVector().Rotation();

	FRotator aimRotator = aimDirection.Rotation();

	FRotator barrelDifferenceRotator = aimRotator - barrelRotation;

	FRotator turretDifferenceRotator = aimRotator - turretRotation;

	//differenceRotator.Pitch
	barrel->Elevate(barrelDifferenceRotator.Pitch);

	turret->RotateTurret(turretDifferenceRotator.Yaw);
}



