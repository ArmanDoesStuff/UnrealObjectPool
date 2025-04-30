//Copyright ArmanDoesStuff 2025

#include "ActorPool.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "ActorPoolBPLibrary.h"

#define LOCTEXT_NAMESPACE "FActorPoolModule"

void FActorPoolModule::StartupModule()
{
	CleanupHandle = FWorldDelegates::OnWorldCleanup.AddStatic(&UActorPoolBPLibrary::WorldCleanup);
}

void FActorPoolModule::ShutdownModule()
{
	if (CleanupHandle.IsValid())
	{
		FWorldDelegates::OnWorldCleanup.Remove(CleanupHandle);
		CleanupHandle.Reset();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FActorPoolModule, ActorPool)
