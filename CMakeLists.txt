cmake_minimum_required(VERSION 3.6)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)

macro(add_msvc_pch pch_header pch_source sources)
  if (MSVC)
    GET_FILENAME_COMPONENT(PrecompiledBasename ${pch_header} NAME_WE)
    set(pch_bin "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
    set(src ${${sources}})

    set_source_files_properties(${pch_source}
        PROPERTIES COMPILE_FLAGS "/Yc\"${pch_header}\" /Fp\"${pch_bin}\""
        OBJECT_OUTPUTS "${pch_bin}")
    set_source_files_properties(${src}
        PROPERTIES COMPILE_FLAGS "/Yu\"${pch_header}\" /FI\"${pch_header}\" /Fp\"${pch_bin}\""
        OBJECT_DEPENDS "${pch_bin}")
    # Add precompiled header to sources
    list(APPEND ${sources} ${pch_source})
  endif ()
endmacro()

include_directories(modules/SFML/include
    src
    )

file(GLOB SRC
    src/*.cpp
    src/app/*.cpp
    src/game/*.cpp
    src/game/entity/*.cpp
    src/renderers/*.cpp
    src/resources/*.cpp
    src/states/*.cpp
    src/ui/*.cpp
    src/utils/*.cpp
    )

set(DIRECTORY "")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(DIRECTORY "debug")
else ()
  set(DIRECTORY "release")
endif ()

add_msvc_pch("pch.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/pch/pch.cpp" SRC)

add_executable(chess ${SRC})

target_link_libraries(chess

    "${CMAKE_CURRENT_SOURCE_DIR}/modules/SFML/${DIRECTORY}/sfml-system-s.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules/SFML/${DIRECTORY}/sfml-window-s.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules/SFML/${DIRECTORY}/sfml-graphics-s.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/modules/SFML/${DIRECTORY}/sfml-main.lib"
    #"${CMAKE_CURRENT_SOURCE_DIR}/modules/SFML/${DIRECTORY}/sfml-audio-s.lib"

    "${CMAKE_CURRENT_SOURCE_DIR}/freetype.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/OpenAL32.lib"
    "${CMAKE_CURRENT_SOURCE_DIR}/libogg.lib"

    opengl32
    Winmm.lib
    gdi32.lib
    )

file(COPY res DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-release")
file(COPY res DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug")