cmake_minimum_required(VERSION 3.20)
project(TradingPlatform CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# Second build configuration: ASan + UBSan. Enable with
#   cmake -S . -B build-sanitized -DENABLE_SANITIZERS=ON
# GCC/Clang only — sanitizers aren't available through this flag on MSVC.
option(ENABLE_SANITIZERS "Build with AddressSanitizer + UndefinedBehaviorSanitizer" OFF)
if(ENABLE_SANITIZERS AND NOT MSVC)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

add_subdirectory(cpp/week01)
add_subdirectory(cpp/week02)
