project "CampaignTrackerApp"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.hpp", "src/**.cpp" }

   includedirs
   {
      "src",
      "%WindowsSdkDir%Include/um",
      "%WindowsSdkDir%Include/shared",
      "ThirdParty/imgui",
	  -- Include Core
	  "../CampaignTrackerCore/src"
   }

   links
   {
      "CampaignTrackerCore",
      "ImGui"
   }

   vpaths
   {
        ["Headers/*"] = { "src/**.hpp" },
        ["Sources/*"] = { "src/**.cpp" }
   }

   targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../bin/int/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
