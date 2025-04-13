// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#include "PoolableActor.h"
#include "ActorPool.h"

void APoolableActor::Release()
{
	if (Pool)
	{
		Pool->ReleaseActor(this);
		SetActorState(false);
		return;
	}
	Destroy();
}

void APoolableActor::OnGet(const FVector& Location, const FRotator& Rotation)
{
	SetActorState(true);
	SetActorLocation(Location);
	SetActorRotation(Rotation);
	OnActorGet();
}

void APoolableActor::Awake(UActorPool* ActorPool)
{
	Pool = ActorPool;
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
	if(Root)
	{
		Root->SetSimulatePhysics(Active);
	}
}
