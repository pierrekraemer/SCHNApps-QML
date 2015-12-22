project(schnapps_utils
	LANGUAGES CXX
)

set(HEADER_FILES
	view.h
	view_renderer.h
)

set(SOURCE_FILES
	view.cpp
	view_renderer.cpp
)

qt5_wrap_ui(UIC_FILES

)

qt5_wrap_cpp(MOC_FILES
	${HEADER_FILES}
)

add_library(${PROJECT_NAME} SHARED
	${HEADER_FILES}
	${SOURCE_FILES}
	${MOC_FILES}
)

if(NOT MSVC)
	target_compile_options(${PROJECT_NAME} PUBLIC "-std=c++11")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
)

qt5_use_modules(${PROJECT_NAME}
	Core Gui Quick OpenGL Widgets
)

target_link_libraries(${PROJECT_NAME}
	${QT_LIBRARIES}
)
