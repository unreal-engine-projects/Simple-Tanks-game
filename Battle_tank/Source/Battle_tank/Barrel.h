// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Barrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed & 1 is max upward speed
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevationDegrees = 30;
	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevationDegrees = 0;
};
