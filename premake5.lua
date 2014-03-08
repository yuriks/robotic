solution "Robotic"
	configurations { "Debug", "Release" }

	flags { "FatalWarnings", "NoRTTI", "Unicode" }
	warnings "Extra"
	floatingpoint "Fast"
	vectorextensions "SSE2"

	targetdir "bin"

	project "Robotic"
		kind "ConsoleApp"
		language "C++"
		files { "src/**.cpp", "src/**.hpp", "src/**.c", "src/**.h" }
		includedirs { "src" }

		links { "SDL2", "SDL2main" }

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
			optimize "Off"

		configuration "Release"
			defines { "NDEBUG" }
			optimize "On"

		configuration "vs*"
			defines { "_CRT_SECURE_NO_WARNINGS" }

		configuration "Windows"
			linkoptions { "/NODEFAULTLIB:msvcrt" }
			links { "OpenGL32" }
