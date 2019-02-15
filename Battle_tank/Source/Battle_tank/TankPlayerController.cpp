// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Engine/Public/DrawDebugHelpers.h"


ATank * ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UTankAimingComponent * aimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(aimingComponent))
	{
		FoundAimingComponent(aimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ATankPlayerController can`t find aiming component!"));
	}

	controlledTank = GetControlledTank();
	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController begin play"));
	if (ensure(controlledTank))
	{
		//UE_LOG(LogTemp, Warning, TEXT("I have a tank: %s"), *tank->GetName());
	}

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(controlledTank)) return;
	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit coordinates: %s"), *hitLocation.ToString());
		controlledTank->AimAt(hitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & location) const
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	// TODO did i set up crosshair position correctly in the playerUI BP??
	FVector2D screenLocation = FVector2D(viewportSizeX * crosshairXlocation, viewportSizeY * crosshairYlocation);
	FVector worldLocation, worldDirection;
	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, worldDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Projection coordinates and direction: %s %s"), *worldLocation.ToString(), *worldDirection.ToString());
		FHitResult hitResult;
		
		//TODO may be we need to start raycasting from camera position, not from crosshair location?
		FVector endLocation = worldLocation + worldDirection * lineTraceRange;
		if (GetWorld()->LineTraceSingleByChannel(hitResult, worldLocation, endLocation, ECollisionChannel::ECC_Visibility))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit coordinates: %s"), *hitResult.ToString());
			//DrawDebugPoint(GetWorld(), hitResult.Location, 10, FColor(255, 0, 255), false, 0.03);
			location = hitResult.Location;
			return true;
		}
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector & lookDirection) const
{
	// TODO implement deprojection above here ??
	return false;
}
