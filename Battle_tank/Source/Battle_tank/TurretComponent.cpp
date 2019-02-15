// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretComponent.h"

void UTurretComponent::Rotate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp(relativeSpeed, -1.0f, 1.0f);
	float rotation = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newRotation = RelativeRotation.Yaw + rotation;

	SetRelativeRotation(FRotator(0, newRotation, 0));
}