// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPool.h"

#include "ActorPoolBPLibrary.h"

#define LOCTEXT_NAMESPACE "FActorPoolModule"


void FActorPoolModule::StartupModule()
{
	FWorldDelegates::OnWorldCleanup.AddStatic(&FActorPoolModule::Cleanup);
}

void FActorPoolModule::ShutdownModule()
{
	FWorldDelegates::OnWorldCleanup.RemoveAll(this);
}

void FActorPoolModule::Cleanup(UWorld* World, bool bSessionEnded, bool bCleanupResources)
{
	UActorPoolBPLibrary::ClearPool();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FActorPoolModule, ActorPool)
