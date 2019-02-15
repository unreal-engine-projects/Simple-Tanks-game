// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMove(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend movement: %f"), Throw);
	if (!ensure(leftTrack && rightTrack)) return;

	leftTrack->SetThrottle(Throw);
	rightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialize(UTrack * left, UTrack * right)
{
	if (!ensure(left && right)) return;

	leftTrack = left;
	rightTrack = right;
}

void UTankMovementComponent::IntendTurn(float Throw)
{
	if (!ensure(leftTrack && rightTrack)) return;

	leftTrack->SetThrottle(Throw);
	rightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector normalized = MoveVelocity.GetSafeNormal();
	FVector tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	float product = FVector::DotProduct(normalized, tankForward);
	
	// order of arguments in this product matters!
	FVector crossProduct = FVector::CrossProduct(normalized, tankForward);

	IntendMove(product);
	IntendTurn(crossProduct.Z);
	//UE_LOG(LogTemp, Warning, TEXT("%s Requesting DirectMove: %s"), *GetOwner()->GetName(), *MoveVelocity.ToString());
}
