// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float relativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 25;
};
