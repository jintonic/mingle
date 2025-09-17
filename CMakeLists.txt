cmake_minimum_required(VERSION 3.16) # CMake quits without it

project(mingle) # project name

set(Geant4_CONFIG_DEBUG TRUE) # let the next command print more information
# http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/InstallationGuide/html/buildtools.html
find_package(Geant4 REQUIRED ui_all vis_all) # search for Geant4Config.cmake
include(${Geant4_USE_FILE}) # Linux cannot find Geant4 header files without it
# set RPATH in installed mingle on Mac (must be set before the next command)
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/RPATH-handling
set(CMAKE_INSTALL_RPATH "${Geant4_INCLUDE_DIRS}/../../lib")
add_executable(mingle mingle.cc)
target_link_libraries(mingle ${Geant4_LIBRARIES})
# put executable in the source directory where *.mac locate
# https://stackoverflow.com/a/9994922/1801749
set_target_properties(mingle PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

if(WIN32)
  # remove Debug and other unnecessary configurations
  # https://cmake.org/pipermail/cmake/2007-March/013081.html
  set(CMAKE_CONFIGURATION_TYPES "Release" CACHE INTERNAL "")
  # change start-up project in VS from ALL_BUILD to mingle
  # https://stackoverflow.com/a/37994396/1801749
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT mingle)
  # automacially add \path\to\mingle to user PATH environment variable
  add_custom_command(TARGET mingle POST_BUILD
    COMMAND cmd /c ${CMAKE_CURRENT_SOURCE_DIR}/mingle.bat)
else()
  install(TARGETS mingle)
  add_custom_target(setup ALL echo
    COMMAND echo run make install to copy mingle executable to a desired folder.
    COMMAND echo)
endif()
