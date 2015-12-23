project(schnapps_core
	LANGUAGES CXX
)

set(HEADER_FILES
	schnapps.h
	plugin.h
	view.h
	map_handler.h
)

set(SOURCE_FILES
	schnapps.cpp
	plugin.cpp
	view.cpp
	map_handler.cpp
)

set(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
	${HEADER_FILES}
	${SOURCE_FILES}
)

if(NOT MSVC)
	target_compile_options(${PROJECT_NAME} PUBLIC "-std=c++11")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CGOGN_SOURCE_DIR}>
	$<BUILD_INTERFACE:${EIGEN3_INCLUDE_DIR}>
)

qt5_use_modules(${PROJECT_NAME}
	Core Gui Quick OpenGL Widgets
)

target_link_libraries(${PROJECT_NAME}
	${CGOGN_LIBRARIES}
	${QT_LIBRARIES}
)
