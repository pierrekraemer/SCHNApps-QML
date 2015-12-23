cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(SCHNApps
	LANGUAGES CXX
)

#### Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

include(cmake/utilities.cmake)

#### Build configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(SCHNAPPS_SOURCE_DIR ${CMAKE_SOURCE_DIR})

#### RPATH
if(UNIX)
    # RPATH is a field in ELF binaries that is used as a hint by the system
    # loader to find needed shared libraries.
    #
    # In the build directory, cmake creates binaries with absolute paths in
    # RPATH.  And by default, it strips RPATH from installed binaries.  Here we
    # use CMAKE_INSTALL_RPATH to set a relative RPATH.  By doing so, we avoid
    # the need to play with LD_LIBRARY_PATH to get applications to run.
    set(CMAKE_INSTALL_RPATH "../lib:../../lib")

    if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_MACOSX_RPATH ON)
    endif()
endif(UNIX)

## Deduce build type of not forced by setting the CMAKE_BUILD_TYPE var
setBuildType()

#### Find CGoGN
set(CGOGN_ROOT_DIR ${CMAKE_SOURCE_DIR}/../CGoGN_2 CACHE STRING "CGoGN root dir")
set(CGOGN_BUILD_DIR ${CMAKE_SOURCE_DIR}/../CGoGN_2-build CACHE STRING "CGoGN build dir")
set(CGOGN_SOURCE_DIR ${CGOGN_ROOT_DIR}/cgogn)
set(CGOGN_LIBRARIES
	${CGOGN_BUILD_DIR}/lib/libcgogn_core.so
	${CGOGN_BUILD_DIR}/lib/libcgogn_utils.so
)


find_package(OpenGL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(GLEW REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)


add_subdirectory(thirdparty)
add_subdirectory(${CGOGN_ROOT_DIR}/thirdparty ${CMAKE_CURRENT_BINARY_DIR}/cgogn_thirdparty)

add_subdirectory(schnapps)

add_subdirectory(plugins)
