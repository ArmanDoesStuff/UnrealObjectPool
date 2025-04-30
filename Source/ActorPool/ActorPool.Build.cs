// Copyright ArmanDoesStuff 2025

using UnrealBuildTool;

public class ActorPool : ModuleRules
{
	public ActorPool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		bUseUnity = false;

		PublicIncludePaths.AddRange(new string[] {
		});

		PrivateIncludePaths.AddRange(new string[] {
		});

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore",
		});

		DynamicallyLoadedModuleNames.AddRange(new string[]
		{
		});
	}
}