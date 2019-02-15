// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.generated.h"

class AProjectile;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * aimingComponent;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UTankMovementComponent * movementComponent;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void AimAt(FVector) const;
	UFUNCTION(BlueprintCallable)
	void Fire();
	
private:
	
	UPROPERTY(EditAnywhere, Category = Firing)
	float launchSpeed = 4000;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> projectileBP = nullptr;
	
	float reloadTimeSec = 3;
	double lastFireTimeSec = 0;
};
