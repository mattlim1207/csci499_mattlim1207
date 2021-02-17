cmake_minimum_required(VERSION 3.15)
project(Caw Version 1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
add_executable(caw Caw.cc)
find_package(glog 0.4.0 REQUIRED)
target_link_libraries(caw glog gflags)

include(FetchContent)

FetchContent_Declare(
	gflags
	GIT_REPOSITORY https://github.com/gflags/gflags.git
	GIT_TAG v2.2.2
)

FetchContent_MakeAvailable(gflags)