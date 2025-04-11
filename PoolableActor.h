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
	UPROPERTY()
	UActorPool* ActorPool;
	UFUNCTION(BlueprintCallable, Category = "Actor Pool")
	virtual void Release();
	virtual void OnGet(const FVector& Location,const FRotator& Rotation);
	void Awake();
    UFUNCTION(BlueprintImplementableEvent, Category = "Pooling")
	void OnActorGet();
	
private:
	void SetActorState(bool Active);
	UPROPERTY()
	UPrimitiveComponent* Root;
};