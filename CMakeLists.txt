cmake_minimum_required(VERSION 3.16) # CMake quits without it

project(mingle) # project name

# http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/InstallationGuide/html/buildtools.html
find_package(Geant4 REQUIRED ui_all vis_all) # search for Geant4Config.cmake
include(${Geant4_USE_FILE}) # Linux cannot find Geant4 header files without it

if ((NOT CMAKE_BUILD_TYPE) AND (NOT WIN32))
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Release;Debug;RelWithDebInfo;MinSizeRel" FORCE)
endif() # set default build type for single-configuration generators, e.g. Makefile

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${Geant4_DIR}/../../.." CACHE PATH "Installation prefix" FORCE)
endif() # Set default installation prefix

if(APPLE) # https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/RPATH-handling
  set(CMAKE_INSTALL_RPATH "${Geant4_DIR}/../..")
endif()  # set RPATH in executable on Mac (must be before add_executable(...))

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cc)
target_link_libraries(${PROJECT_NAME} ${Geant4_LIBRARIES})
install(TARGETS ${PROJECT_NAME}) # enable cmake --install
