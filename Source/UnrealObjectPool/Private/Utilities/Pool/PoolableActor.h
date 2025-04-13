// Intellectual Property of AWAN SOFTWORKS LTD. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolableActor.generated.h"

class UActorPool;

UCLASS()
class APoolableActor : public AActor
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Actor Pool")
	virtual void Release();
	virtual void OnGet(const FVector& Location = FVector::ZeroVector, const FRotator& Rotation = FRotator::ZeroRotator);
    UFUNCTION(BlueprintImplementableEvent, Category = "Pooling")
	void OnActorGet();
	void Awake(UActorPool* ActorPool);

private:
	void SetActorState(bool Active);
	UPROPERTY()
	UActorPool* Pool;
	UPROPERTY()
	UPrimitiveComponent* Root;
};