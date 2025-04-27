// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#include "PoolableActor.h"
#include "ActorPoolBPLibrary.h"

void APoolableActor::Release()
{
	UActorPoolBPLibrary::ReleaseActor(this);
	SetActorState(false);
}

void APoolableActor::OnGet(const FVector& Location, const FRotator& Rotation)
{
	SetActorState(true);
	SetActorLocation(Location);
	SetActorRotation(Rotation);
	OnActorGet();
}

void APoolableActor::Awake()
{
	Root = Cast<UPrimitiveComponent>(GetRootComponent());
	if (!Root)
	{
		UE_LOG(LogTemp, Error, TEXT("Root component is invalid!"));
	}
}

void APoolableActor::SetActorState(const bool Active)
{
	SetActorTickEnabled(Active);
	SetActorHiddenInGame(!Active);
	SetActorEnableCollision(Active);
	if (Root)
	{
		Root->SetSimulatePhysics(Active);
	}
}
