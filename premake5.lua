workspace "Fern"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = 'Fern/vendor/GLFW/include'

include "Fern/vendor/GLFW"

project "Fern"
	location "Fern"
	kind "SharedLib"
	language "C++" 

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fnpch.h"
	pchsource "Fern/src/fnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "default"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FN_PLATFORM_WINDOWS",
			"FN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FN_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "FN_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "FN_DIST"
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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Fern/vendor/spdlog/include",
		"Fern/src"
	}

	links
	{
		"Fern"
	}

	filter "system:windows"
		cppdialect "default"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FN_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "FN_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "FN_DIST"
		optimize "On"