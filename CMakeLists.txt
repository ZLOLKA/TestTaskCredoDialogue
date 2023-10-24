cmake_minimum_required(VERSION 3.26)

project(StarWarsTestTask)

file(GLOB src_files
    "./src/*.cpp"
    "./src/**/*.cpp"
    "./src/**/**/*.cpp"
)

add_library(StarWarsTestTaskLib STATIC ${src_files})

target_include_directories(StarWarsTestTaskLib PUBLIC "./include/")
target_compile_options(StarWarsTestTaskLib PRIVATE
    -Werror
)
target_compile_options(StarWarsTestTaskLib PUBLIC
    -pedantic-errors -Wall -Wextra -Wpedantic -Wpedantic-macros
    -ftemplate-backtrace-limit=0
    -O3
)

# Include https://gitlab.com/cky/cpp17-json.git lib
target_include_directories(StarWarsTestTaskLib PRIVATE "./third-party/cpp17-json/")

if(NOT DEFINED USE_ASSERT_AS_THROW)
    set(USE_ASSERT_AS_THROW 1)
endif()
message("\nUSE_ASSERT_AS_THROW=" ${USE_ASSERT_AS_THROW} "\n")
target_compile_definitions(StarWarsTestTaskLib PUBLIC USE_ASSERT_AS_THROW=${USE_ASSERT_AS_THROW})

add_executable(StarWarsTestTask "./main.cpp")
target_link_libraries(StarWarsTestTask PUBLIC StarWarsTestTaskLib)
target_compile_options(StarWarsTestTask PRIVATE -Werror)

