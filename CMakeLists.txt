cmake_minimum_required(VERSION 3.28)
project(TankGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(SFML)

add_executable(TankGame src/main.cpp
        src/Game.cpp
        src/Game.hpp
        src/Tank.cpp
        src/Tank.hpp
        src/MathUtils.hpp
        src/MathUtils.cpp
        src/Battlefield.cpp
        src/Battlefield.hpp
        src/Utils.hpp
        src/Utils.cpp
        src/SceneNode.cpp
        src/SceneNode.hpp)
target_link_libraries(TankGame PRIVATE sfml-graphics)
target_compile_features(TankGame PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
            TARGET TankGame
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:TankGame>
            VERBATIM)
endif()

install(TARGETS TankGame)
