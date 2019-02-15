// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank * controlledTank = Cast<ATank>(GetPawn());
	APlayerController * playerController = GetWorld()->GetFirstPlayerController();
	ATank * playerTank = Cast<ATank>(playerController->GetPawn());
	if (!controlledTank || !playerTank) return;

	MoveToActor(playerTank, acceptanceRadius);

	controlledTank->AimAt(playerTank->GetActorLocation());
	//controlledTank->Fire();
}