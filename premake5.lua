workspace "OEP"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	    defines
		{
			"OEP_BUILD_DLL",
			"OEP_PLATFORM_WINDOWS"	
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OEP_DEBUG"
		symbols "On"
    filter "configurations:Release"
		defines "OEP_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "OEP_DIST"
		symbols "On"

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
		symbols "On"
    filter "configurations:Release"
		defines "OEP_RELEASE"
		symbols "On"
	filter "configurations:Dist"
		defines "OEP_DIST"
		symbols "On"