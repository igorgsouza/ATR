# ########################
# # SETTING DEFINITIONS ##
# ########################

# CMake minimum version
cmake_minimum_required(VERSION 3.0.0)

# C++ Standard version
set(CMAKE_CXX_STANDARD 20)

# ## Searches for the VCPKG
if(DEFINED ENV{VCPKG_ROOT})
	set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

# ########################
# # PROJECT DEFINITIONS ##
# ########################
project(main LANGUAGES CXX VERSION 0.1.0)

find_package(Boost COMPONENTS system json REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

include_directories(include)
link_directories(src)
add_subdirectory(src)
link_libraries(atr_lib)

if(MSVC OR MSYS OR MINGW)
	target_link_libraries(${PROJECT_NAME} ws2_32)
endif()