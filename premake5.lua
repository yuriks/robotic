solution "Robotic"
	configurations { "Debug", "Release" }

	flags { "FatalWarnings", "NoExceptions", "NoRTTI", "Unicode" }
	warnings "Extra"
	floatingpoint "Fast"
	vectorextensions "SSE2"

	targetdir "bin"

	project "Robotic"
		kind "ConsoleApp"
		language "C++"
		files { "src/**.cpp", "src/**.hpp" }

		links { "SDL2" }

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
			optimize "Off"

		configuration "Release"
			defines { "NDEBUG" }
			optimize "On"
