// ArmanDoesStuff 2025

#pragma once

#include "Modules/ModuleManager.h"

class FActorPoolModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	FDelegateHandle CleanupHandle;
};
