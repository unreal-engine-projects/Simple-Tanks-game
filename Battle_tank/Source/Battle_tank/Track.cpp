// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"

void UTrack::SetThrottle(float throttle)
{
	FString name = GetName();
	
	FVector forceApplied = GetForwardVector() * throttle * maxTrackDrivingForce;
	FVector forceLocation = GetComponentLocation(); 
	// we need tank`s primitive component to apply force to
	UPrimitiveComponent * tankPrimitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankPrimitiveComponent->AddForceAtLocation(forceApplied, forceLocation);
	//UE_LOG(LogTemp, Warning, TEXT("%s throttling force: %s at location: %s"), *name, *forceApplied.ToString(), *forceLocation.ToString());
}