set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.10)
project(morse VERSION
1.0
DESCRIPTION "Eine C Implementierung eines Morse Code Übersetzers")

# Besonderheiten fuer Debug- und Release
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -O3")

# Lib libtext.a erzeugen
add_subdirectory(functions)

# Includes
include_directories(${PROJECT_SOURCE_DIR}/functions/include)

# Die Datei die das main enthaelt hier eintragen
add_executable(${PROJECT_NAME} main.c)


# Die Library libtext.a hinzulinken
target_link_libraries(${PROJECT_NAME} morsefunctions)