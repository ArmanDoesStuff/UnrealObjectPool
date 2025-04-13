// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ActorPool.generated.h"


/**
 * 
 */
UCLASS()
class UActorPool : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Actor Pool")
	APoolableActor* GetActor(const TSubclassOf<APoolableActor> ActorToGet, const FVector Location = FVector::ZeroVector, const FRotator Rotation = FRotator::ZeroRotator);
	//templates declaration
	template <class T>
	T* GetActor(TSubclassOf<APoolableActor> ActorToGet);
	template <class T>
	T* GetActor(TSubclassOf<APoolableActor> ActorToGet, const FVector& Location, const FRotator& Rotation);
	template <class T>
	T* GetActor(TSubclassOf<APoolableActor> ActorToGet, const FTransform& Transform);
	void ReleaseActor(APoolableActor* ActorToRelease);
	TArray<APoolableActor*> GetAllPooledActors();

private:
	TMap<FString, TArray<APoolableActor*>> Pool;
};

//templates implementation
template <class T>
T* UActorPool::GetActor(const TSubclassOf<APoolableActor> ActorToGet)
{
	return Cast<T>(GetActor(ActorToGet, FVector::Zero(), FRotator::ZeroRotator));
}

template <class T>
T* UActorPool::GetActor(const TSubclassOf<APoolableActor> ActorToGet, const FVector& Location, const FRotator& Rotation)
{
	return Cast<T>(GetActor(ActorToGet, Location, Rotation));
}

template <class T>
T* UActorPool::GetActor(const TSubclassOf<APoolableActor> ActorToGet, const FTransform& Transform)
{
	return GetActor<T>(ActorToGet, Transform.GetLocation(), Transform.Rotator());
}
