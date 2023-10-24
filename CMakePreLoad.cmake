macro(cache_set)
    set(${ARGN} CACHE INTERNAL "" FORCE)
endmacro()

cache_set(CMAKE_GENERATOR Ninja) 

cache_set(CMAKE_CXX_STANDARD 17)
cache_set(CMAKE_CXX_STANDARD_REQUIRED True)
cache_set(CMAKE_CXX_COMPILER clang++)

cache_set(CMAKE_EXPORT_COMPILE_COMMANDS True) # For work with clangd

