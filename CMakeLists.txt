cmake_minimum_required(VERSION 2.9) # CMake quits without it

project(tiny) # project name

find_package(Geant4 REQUIRED ui_all vis_all) # search for Geant4Config.cmake
include(${Geant4_USE_FILE}) # Linux cannot find Geant4 header files without it
add_executable(tiny tiny.cc)
target_link_libraries(tiny ${Geant4_LIBRARIES})

