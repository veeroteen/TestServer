cmake_minimum_required(VERSION 3.22)
project(TestServer)
set(CMAKE_CXX_STANDARD 17)

include_directories (Receiver ${CMAKE_CURRENT_SOURCE_DIR}/Receiver)

include(FetchContent)
FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG 32da69a36f84c5255af8a994951918c258bac601
)

FetchContent_MakeAvailable(boost)


add_executable(TestServer main.cpp Receiver/Server.cpp Receiver/Server.h)

target_link_libraries(TestServer PRIVATE Boost::asio wsock32 ws2_32)