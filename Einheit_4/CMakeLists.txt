# Bitte ein Unterverzeichnis ./build erstellen

# Linux/OSX
# Debug mit cmake -DCMAKE_BUILD_TYPE=Debug ..
# Release mit cmake -DCMAKE_BUILD_TYPE=Release ..
# Compilieren mit make

# Windows Visual Studio (am Beispiel VS 2017)
# MSBuild Files erstellen cmake -G "Visual Studio 15 2017" ..
# Debug mit msbuild ALL_BUILD.vcxproj /p:configuration=release
# Release mit msbuild ALL_BUILD.vcxproj /p:configuration=debug

# MinGW (alle Varianten)
# Debug mit cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
# Release mit cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
# Compilieren mit mingw32-make.exe

cmake_minimum_required(VERSION 3.10)

# Name des Projekts
project ( 	hex
	        VERSION 1.0
	        DESCRIPTION "Eine Applikation zum anzeigen von hexadezimale Werte aus einer Datei")

# C Standart
set(CMAKE_C_STANDARD 23)

# Falls Definitionen benoetigt werden
# add_definitions(-D...)

# Unterschiedliche Versionen fuer Debug und Release
set(CMAKE_C_FLAGS_DEBUG_INIT "-Wall -g3 -O0")
set(CMAKE_C_FLAGS_RELEASE_INIT "-Wall -O3 -s")

# Astyle Option in make
add_custom_target (astyle
	COMMAND
	#COMMAND astyle -r ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.c --exclude=build
	COMMAND astyle -r ${PROJECT_SOURCE_DIR}/*.c --exclude=build
	VERBATIM
)

# Erstellen der Executeable
add_executable(${PROJECT_NAME} main.c)
