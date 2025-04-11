// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#include "PoolableActor.h"
#include "ActorPool.h"

void APoolableActor::Release()
{
	if (ActorPool)
	{
		ActorPool->ReleaseActor(this);
		SetActorState(false);
		return;
	}
	Destroy();
}

void APoolableActor::OnGet(const FVector& Location = FVector::ZeroVector, const FRotator& Rotation = FRotator::ZeroRotator)
{
	SetActorState(true);
	SetActorLocation(Location);
	SetActorRotation(Rotation);
	OnActorGet();
}

void APoolableActor::Awake()
{
	Root = Cast<UPrimitiveComponent>(GetRootComponent());
}

void APoolableActor::SetActorState(const bool Active)
{
	SetActorTickEnabled(Active);
	SetActorHiddenInGame(!Active);
	SetActorEnableCollision(Active);
	Root->SetSimulatePhysics(Active);
}
