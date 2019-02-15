// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float maxTrackDrivingForce = 40000000;
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);
private:
	
};
