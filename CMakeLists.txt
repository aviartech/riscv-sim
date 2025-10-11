cmake_minimum_required(VERSION 3.14)

project(RISCV-SIM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Library ----
add_library(riscv-sim-lib
    src/Cpu.cpp
    src/Memory.cpp
    src/RegisterFile.cpp
    src/ISAController.cpp
)

target_include_directories(riscv-sim-lib PUBLIC include)

if (MSVC)
    target_compile_options(riscv-sim-lib PRIVATE /W4 /permissive-)
else()
    target_compile_options(riscv-sim-lib PRIVATE -Wall -Wextra -pedantic)
endif()

# ---- Executable ----
add_executable(riscv-sim main.cpp)
target_link_libraries(riscv-sim PRIVATE riscv-sim-lib)

# ---- GoogleTest (auto-fetch) ----
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# Avoid messing with parent project's CRT flags (Windows)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ---- Tests ----
add_executable(riscv-sim-tests
    tests/test_registerfile.cpp
    # tests/test_isacontroller.cpp
)

target_link_libraries(riscv-sim-tests
    PRIVATE
    riscv-sim-lib
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(riscv-sim-tests)
