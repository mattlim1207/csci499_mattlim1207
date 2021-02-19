cmake_minimum_required(VERSION 3.15)
project(Caw)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
add_executable(caw Caw.cc)
add_executable(server KVStore.cc)


find_package(glog 0.4.0 REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)
target_link_libraries(caw glog gflags)
target_link_libraries(server glog grpc++)

include(FetchContent)

FetchContent_Declare(
	gflags
	GIT_REPOSITORY https://github.com/gflags/gflags.git
	GIT_TAG v2.2.2
)

FetchContent_MakeAvailable(gflags)