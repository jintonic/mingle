cmake_minimum_required(VERSION 3.5) # CMake quits without it

project(mingle) # project name

set(Geant4_CONFIG_DEBUG TRUE) # let the next command print more information
find_package(Geant4 REQUIRED ui_all vis_all) # search for Geant4Config.cmake
include(${Geant4_USE_FILE}) # Linux cannot find Geant4 header files without it
# set RPATH in installed mingle (must be set before the next command)
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/RPATH-handling
set(CMAKE_INSTALL_RPATH "${Geant4_INCLUDE_DIRS}/../../lib")
add_executable(mingle mingle.cc)
target_link_libraries(mingle ${Geant4_LIBRARIES})

if(WIN32)
  # remove Debug and other unnecessary configurations
  set(CMAKE_CONFIGURATION_TYPES "Release" CACHE INTERNAL "")
  # https://stackoverflow.com/a/37994396/1801749
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT mingle)
endif()

install(TARGETS mingle)

