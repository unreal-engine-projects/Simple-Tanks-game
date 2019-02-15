// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = Setup)
	ATank * GetControlledTank() const;
	virtual void BeginPlay() override;
	void AimTowardsCrosshair();

protected:
	
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent * aimingComponent);

private:
	UPROPERTY(EditAnywhere)
	float crosshairXlocation = 0.5f,
	UPROPERTY(EditAnywhere)
	crosshairYlocation = 0.33333f,
	UPROPERTY(EditAnywhere)
	lineTraceRange = 1000000.0f;		// 10km?
	ATank * controlledTank;
	bool GetSightRayHitLocation(FVector &) const;
	bool GetLookDirection(FVector2D, FVector &) const;
};
