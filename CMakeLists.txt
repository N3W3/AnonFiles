# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(MetaForge C)

# Add the include/ directory for headers
include_directories(include)

# Add the executable (name: anonfiles, source: main.c)
add_executable(metaForge src/main.c)
