// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrel.h"

void UBarrel::Elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp(relativeSpeed, -1.0f, 1.0f);
	//UE_LOG(LogTemp, Warning, TEXT("Barrel -> Elevate"));
	float elevation = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newElevation = RelativeRotation.Pitch + elevation;
	float clamped = FMath::Clamp(newElevation, minElevationDegrees, maxElevationDegrees);
	SetRelativeRotation(FRotator(clamped, 0, 0));
}