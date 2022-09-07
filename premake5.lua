workspace "MiravEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "MiravEngine/extlibs/GLFW/include"

include "MiravEngine/extlibs/GLFW"


project "MiravEngine"
	location "MiravEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mvpch.h"
	pchsource "MiravEngine/src/mvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/extlibs/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MV_PLATFORM_WINDOWS",
			"MV_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MV_DIST"
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
		"MiravEngine/extlibs/spdlog/include",
		"MiravEngine/src"
	}

	links
	{
		"MiravEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MV_DIST"
		optimize "On"