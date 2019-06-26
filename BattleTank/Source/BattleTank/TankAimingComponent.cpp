// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::setBarrelReference(UStaticMeshComponent * barrelToSet)
{

	barrel = barrelToSet;
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

	auto aimDirection = outLaunchVelocity.GetSafeNormal();

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		outLaunchVelocity,
		startingLocation,
		worldSpace,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace)) {


		FString tankName = GetOwner()->GetName();

		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *tankName, *worldSpace.ToString(), *aimDirection.ToString());
		MoveBarrel(aimDirection);
	}
	

}

void UTankAimingComponent::MoveBarrel(FVector aimDirection) {

	FRotator barrelRotation = barrel->GetForwardVector().Rotation();

	FRotator aimRotator = aimDirection.Rotation();

	FRotator differenceRotator = barrelRotation - aimRotator;
}



