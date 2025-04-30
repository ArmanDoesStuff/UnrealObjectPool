//Copyright ArmanDoesStuff 2025

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolableActor.generated.h"

class UPoolMaster;

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="An Actor that can be released to a pool for later retrieval."))
class APoolableActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, meta = (Keywords = "Actor Pool Release"), Category = "Actor Pool")
	virtual void Release();
	virtual void GetActor(const FVector& Location = FVector::ZeroVector, const FRotator& Rotation = FRotator::ZeroRotator);
    UFUNCTION(BlueprintImplementableEvent, Category = "Pooling")
	void OnActorGet();
	void Awake();

private:
	void SetActorState(bool Active);
	UPROPERTY()
	UPrimitiveComponent* Root;
};