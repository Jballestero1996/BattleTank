// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override; 

	ATank* GetPlayerTank() const;
	
	ATank* GetControlledTank() const; 
public: 
	virtual void Tick(float DeltaTime) override;
};