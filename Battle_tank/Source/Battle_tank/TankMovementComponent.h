// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Track.h"
#include "TankMovementComponent.generated.h"

/**
 *  Driving tank`s tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	

public:
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMove(float Throw);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTrack * left, UTrack * right);
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurn(float Throw);
	// called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	
	UTrack * leftTrack;
	UTrack * rightTrack;
};
