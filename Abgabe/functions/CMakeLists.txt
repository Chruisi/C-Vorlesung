add_library(morsefunctions STATIC
"src/decode.c"
"src/encode.c"
"src/help_functions.c"
"src/input_output.c"
"src/morse_tables.c"
)
target_include_directories(morsefunctions PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(morsefunctions PRIVATE VERSION=v1.0.0)