//Copyright ArmanDoesStuff 2025

#include "ActorPoolBPLibrary.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "PoolableActor.h"

TMap<FString, TArray<APoolableActor*>> UActorPoolBPLibrary::Pool;

UActorPoolBPLibrary::UActorPoolBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UActorPoolBPLibrary::WorldCleanup(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	Pool.Empty();
}

APoolableActor* UActorPoolBPLibrary::GetPoolableActor(UObject* WorldContextObject, const TSubclassOf<APoolableActor> ActorToGet, const FVector Location, const FRotator Rotation)
{
	if (!ActorToGet)
	{
		UE_LOG(LogTemp, Error, TEXT("ActorPool::GetPoolableActor called with null Actor"));
		return nullptr;
	}
	const FString ActorType = ActorToGet->GetName();
	if (Pool.Contains(ActorType))
	{
		TArray<APoolableActor*>& ActorArray = Pool[ActorType];
		while (ActorArray.Num() > 0)
		{
			APoolableActor* PooledActor = ActorArray.Pop();;
			if (IsValid(PooledActor) && !PooledActor->IsPendingKillPending())
			{
				PooledActor->GetActor(Location, Rotation);
				return PooledActor;
			}
		}
	}
	if (UWorld* World = WorldContextObject->GetWorld())
	{
		if (APoolableActor* PooledActor = World->SpawnActor<APoolableActor>(ActorToGet))
		{
			PooledActor->Awake();
			PooledActor->GetActor(Location, Rotation);
			return PooledActor;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Pool Spawning while not in world")));
	return nullptr;
}


void UActorPoolBPLibrary::ReleaseActor(APoolableActor* ActorToRelease)
{
	TArray<APoolableActor*>& ActorArray = Pool.FindOrAdd(ActorToRelease->GetClass()->GetName());
	ActorArray.Add(ActorToRelease);
}

TArray<APoolableActor*> UActorPoolBPLibrary::GetAllPooledActors()
{
	TArray<APoolableActor*> AllActors;
	for (const TTuple<FString, TArray<APoolableActor*>>& Item : Pool)
	{
		const TArray<APoolableActor*>& Actors = Item.Value;
		AllActors.Append(Actors);
	}
	return AllActors;
}
