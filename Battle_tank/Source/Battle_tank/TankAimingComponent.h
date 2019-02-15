// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading
};

class UBarrel;
class UTurretComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UBarrel * barrelToSet, UTurretComponent * turretToSet);

public:	
	
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringStatus status = EFiringStatus::Aiming;
	// Sets default values for this component's properties
	UTankAimingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector targetLocation, float speed);
	UBarrel * GetBarrelComponent();
		
private:
	UBarrel * barrel;
	UTurretComponent * turret;

	void MoveBarrel(FVector direction);
};
