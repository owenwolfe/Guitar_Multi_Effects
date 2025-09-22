cmake_minimum_required(VERSION 3.10)
project(GuitarEffectsProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    main.cpp
    Distortion.cpp
    Delay.cpp
    EffectChain.cpp
    AudioIO.cpp
)

# Find required libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(SNDFILE REQUIRED sndfile)
pkg_check_modules(PORTAUDIO REQUIRED portaudio-2.0)

include_directories(
    ${SNDFILE_INCLUDE_DIRS}
    ${PORTAUDIO_INCLUDE_DIRS}
    .
)

link_directories(
    ${SNDFILE_LIBRARY_DIRS}
    ${PORTAUDIO_LIBRARY_DIRS}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${SNDFILE_LIBRARIES}
    ${PORTAUDIO_LIBRARIES}
)

