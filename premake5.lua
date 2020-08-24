workspace "OEP"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "OEP/vendor/GLFW/include"
IncludeDir["Glad"] = "OEP/vendor/Glad/include"
IncludeDir["ImGui"] = "OEP/vendor/imgui"

include "OEP/vendor/GLFW"
include "OEP/vendor/Glad"
include "OEP/vendor/imgui"

project "OEP"
	location "OEP"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "oeppch.h"
	pchsource "OEP/src/oeppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	    defines
		{
			"OEP_BUILD_DLL",
			"OEP_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OEP_DEBUG"
		buildoptions "/MDd"
		symbols "On"

    filter "configurations:Release"
		defines "OEP_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "OEP_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"OEP/vendor/spdlog/include",
		"OEP/src"
	}

	links
	{
		"OEP"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"OEP_PLATFORM_WINDOWS"	
	}

	filter "configurations:Debug"
		defines "OEP_DEBUG"
		buildoptions "/MDd"
		optimize "On"
    filter "configurations:Release"
		defines "OEP_RELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "OEP_DIST"
		buildoptions "/MD"
		optimize "On"