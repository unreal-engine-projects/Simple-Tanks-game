// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "Barrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	aimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector targetLocation) const
{
	aimingComponent->AimAt(targetLocation, launchSpeed);
	
}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank is firing"));
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTimeSec) > reloadTimeSec;
	UBarrel * barrel = aimingComponent->GetBarrelComponent();
	if (!ensure(barrel)) return;
	
	if (isReloaded)
	{
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			projectileBP, 
			barrel->GetSocketLocation(FName("Projectile")), 
			barrel->GetSocketRotation(FName("Projectile"))
		);
		projectile->Launch(launchSpeed);
		lastFireTimeSec = FPlatformTime::Seconds();
	}
	
}

