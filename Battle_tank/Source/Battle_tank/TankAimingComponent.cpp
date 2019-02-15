// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Barrel.h"
#include "TurretComponent.h"

void UTankAimingComponent::Initialize(UBarrel * barrelToSet, UTurretComponent * turretToSet)
{
	barrel = barrelToSet;
	turret = turretToSet;
}

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;	// TODO: should this really tick?

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector targetLocation, float speed)
{
	if (!barrel) return;

	// GetName() returns memory address, not the name WTF??
	FString name = GetOwner()->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("% tank aiming at: %s"), *name, *targetLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("%s got target: %s and speed: %s"), *name, *targetLocation.ToString(), *(FString::SanitizeFloat(speed)));

	FVector launchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		launchVelocity,
		startLocation,
		targetLocation,
		speed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor *>(),
		false
	)) {
		FVector aimDirection = launchVelocity.GetSafeNormal();		//get unit vector
		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s direction"), *name, *aimDirection.ToString());
		MoveBarrel(aimDirection);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s couldnt find target!! barrel location is: %s"), *name, *startLocation.ToString());
	}

}

UBarrel * UTankAimingComponent::GetBarrelComponent()
{
	return barrel;
}

void UTankAimingComponent::MoveBarrel(FVector direction)
{
	FRotator currentRotation = barrel->GetForwardVector().Rotation();
	FRotator aimRotation = direction.Rotation();
	FRotator delta = aimRotation - currentRotation;
	barrel->Elevate(delta.Pitch);
	turret->Rotate(delta.Yaw);
}

