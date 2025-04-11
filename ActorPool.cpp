// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#include "ActorPool.h"
#include "PoolableActor.h"

APoolableActor* UActorPool::GetActor(const TSubclassOf<APoolableActor> ActorToGet, const FVector Location, const FRotator Rotation)
{
	if (!ActorToGet)
	{
		UE_LOG(LogTemp, Error, TEXT("ActorPool::GetActor called with null Actor"));
		return nullptr;
	}
	const FString ActorType = ActorToGet->GetName();
	if (Pool.Contains(ActorType))
	{
		while (Pool[ActorType].Num() > 0)
		{
			if (APoolableActor* PooledActor = Pool[ActorType].Pop(); IsValid(PooledActor) && !PooledActor->
				IsPendingKillPending())
			{
				PooledActor->OnGet(Location, Rotation);
				return PooledActor;
			}
		}
	}
	if (UWorld* World = GetWorld())
	{
		if (APoolableActor* PooledActor = World->SpawnActor<APoolableActor>(ActorToGet))
		{
			PooledActor->ActorPool = this;
			PooledActor->Awake();
			PooledActor->OnGet(Location, Rotation);
			return PooledActor;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Pool Spawning while not in world")));
	return nullptr;
}


void UActorPool::ReleaseActor(APoolableActor* ActorToRelease)
{
	TArray<APoolableActor*>& ActorArray = Pool.FindOrAdd(ActorToRelease->GetClass()->GetName());
	ActorArray.Add(ActorToRelease);
}

TArray<APoolableActor*> UActorPool::GetAllPooledActors()
{
	TArray<APoolableActor*> AllActors;
	for (const TTuple<FString, TArray<APoolableActor*>>& Item : Pool)
	{
		const TArray<APoolableActor*>& Actors = Item.Value;
		AllActors.Append(Actors);
	}
	return AllActors;
}
