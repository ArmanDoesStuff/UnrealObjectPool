//Copyright ArmanDoesStuff 2025

#pragma once

#include "PoolableActor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorPoolBPLibrary.generated.h"

UCLASS()
class UActorPoolBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	static void WorldCleanup(UWorld* World, bool bSessionEnded, bool bCleanupResources);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", Keywords = "Actor Pool Spawn Get"), Category = "Actor Pool")
	static APoolableActor* GetPoolableActor(UObject* WorldContextObject, const TSubclassOf<APoolableActor> ActorToGet, const FVector Location = FVector::ZeroVector, const FRotator Rotation = FRotator::ZeroRotator);
	static void ReleaseActor(APoolableActor* ActorToRelease);
	static TArray<APoolableActor*> GetAllPooledActors();
	
	static TMap<FString, TArray<APoolableActor*>> Pool;
};
