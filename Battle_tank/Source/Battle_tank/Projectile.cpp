// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	movementComponent->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::Launch(float speed)
{
	movementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	movementComponent->Activate();
}

