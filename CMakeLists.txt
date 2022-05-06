
cmake_minimum_required (VERSION 3.0.2)

# Basic project setup
cmake_policy(SET CMP0048 NEW)
project (SDL2_Project_Template VERSION 0.1.1)


# Find required libraries

# find package using PkgConfig or find_package.
# find_package script in Cmake directory provided by https://github.com/tcbrindle/sdl2-cmake-scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(PkgConfig)
if (PKGCONFIG_FOUND)
	pkg_check_modules(SDL2 REQUIRED sdl2>=2.0.7)
	pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image>=2.0.1)
	pkg_check_modules(SDL2TTF REQUIRED SDL2_ttf>=2.0.15)
else(PKGCONFIG_FOUND) # if there is no PkgConfig
	find_package(SDL2 2.0.7 REQUIRED)
	find_package(SDL2IMAGE 2.0.1 REQUIRED)
	find_package(SDL2TTF 2.0.15 REQUIRED)
endif(PKGCONFIG_FOUND)


if(CMAKE_COMPILER_IS_GNUCXX) # add debug warnings for gcc
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)


# Find source files
FILE(GLOB_RECURSE SourceFiles src/*.c)
FILE(GLOB_RECURSE HeaderFiles src/*.h)
FILE(GLOB_RECURSE ResourceFiles resources/*)


# Icon file selection
if(APPLE)
list(APPEND ResourceFiles icon/icon.icns)
else()
list(APPEND ResourceFiles icon/icon.png)
endif()


# Create the executable

if (PKGCONFIG_FOUND) # Switch build between PkgConfig vs find_package
	# Create the executable
	include_directories (
		${SDL2_INCLUDE_DIRS}
		${SDL2IMAGE_INCLUDE_DIRS}
		${SDL2TTF_INCLUDE_DIRS}
		)
	add_executable (SDL2_Project_Template ${SourceFiles} ${ResourceFiles})
	target_link_libraries (SDL2_Project_Template
		${SDL2_LINK_LIBRARIES}
		${SDL2IMAGE_LINK_LIBRARIES}
		${SDL2TTF_LINK_LIBRARIES}
		)
else(PKGCONFIG_FOUND) # if there is no PkgConfig
	# Create the executable
	include_directories (
		${SDL2_INCLUDE_DIR}
		${SDL2_IMAGE_INCLUDE_DIRS}
		${SDL2_TTF_INCLUDE_DIRS}
		)
	add_executable (SDL2_Project_Template ${SourceFiles} ${ResourceFiles})
	target_link_libraries (SDL2_Project_Template
		${SDL2_LIBRARY}
		${SDL2_IMAGE_LIBRARIES}
		${SDL2_TTF_LIBRARIES}
		)
endif(PKGCONFIG_FOUND)

# include directories for the base Project
include_directories (
	"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/src/kissfft"
	"${PROJECT_SOURCE_DIR}/src/render_helper"
	"${PROJECT_SOURCE_DIR}/src/socket"
	)


# add math and threads library if its linux
if (UNIX)
  find_package (Threads)
  target_link_libraries (SDL2_Project_Template m ${CMAKE_THREAD_LIBS_INIT})
endif (UNIX)

# add dirent directory if MSVC
if (MSVC)
  include_directories ("${PROJECT_SOURCE_DIR}/src/dirent")
endif (MSVC)




# Set target properties for various platforms
set_target_properties(SDL2_Project_Template PROPERTIES
  MACOSX_BUNDLE TRUE
  MACOSX_BUNDLE_ICON_FILE "icon.icns"
  MACOSX_BUNDLE_SHORT_VERSION_STRING "${SDL2_Project_Template_VERSION_MAJOR}.${SDL2_Project_Template_VERSION_MINOR}"
  MACOSX_BUNDLE_LONG_VERSION_STRING "${SDL2_Project_Template_VERSION_MAJOR}.${SDL2_Project_Template_VERSION_MINOR}.${SDL2_Project_Template_VERSION_PATCH}"
  MACOSX_BUNDLE_BUNDLE_VERSION "${SDL2_Project_Template_VERSION_MAJOR}.${SDL2_Project_Template_VERSION_MINOR}.${SDL2_Project_Template_VERSION_PATCH}"
  MACOSX_BUNDLE_COPYRIGHT "Copyright (c) 2022 Corwin Hansen"
  MACOSX_BUNDLE_INFO_STRING "${SDL2_Project_Template_VERSION_MAJOR}.${SDL2_Project_Template_VERSION_MINOR}.${SDL2_Project_Template_VERSION_PATCH}, Copyright 2022 Corwin Hansen"
  RESOURCE "${ResourceFiles}"
  WIN32_EXECUTABLE TRUE
  C_STANDARD 99)


  # Add install targets
  install (TARGETS SDL2_Project_Template DESTINATION bin)
  install (FILES ${HeaderFiles} DESTINATION include)


# Packaging
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VENDOR "Corwin Hansen")
include (CPack)
