// Shoot Them Up Game. All Rights Reserved 

using UnrealBuildTool;

public class ShootThemUp : ModuleRules
{
	public ShootThemUp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		PublicIncludePaths.AddRange(new string[] { "ShootThemUp/Public/Player", "ShootThemUp/Public/Components", "ShootThemUp/Public/Dev" });

		
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		PublicIncludePaths.AddRange(new string[]
		{
			"ShootThemUp/Player",
			"ShootThemUp/Components",
			"ShootThemUp/Dev",
			"ShootThemUp/Weapon"
		});
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
