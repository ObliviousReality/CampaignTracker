-- premake5.lua
workspace "Campaign Tracker"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "CampaignTrackerApp"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "CampaignTrackerCore/Build-Core.lua"
group ""

include "CampaignTrackerApp/Build-App.lua"
