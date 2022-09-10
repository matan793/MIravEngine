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
IncludeDir["Glad"] = "MiravEngine/extlibs/Glad/include"

include "MiravEngine/extlibs/GLFW"
include "MiravEngine/extlibs/Glad"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links 
	{ 
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MV_PLATFORM_WINDOWS",
			"MV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MV_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "MV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MV_DIST"
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
		buildoptions "/MDd"	
		symbols "On"

	filter "configurations:Release"
		defines "MV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "MV_DIST"
		buildoptions "/MD"
		optimize "On"