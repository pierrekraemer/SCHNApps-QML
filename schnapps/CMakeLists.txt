add_subdirectory(core)
add_subdirectory(utils)

project(schnapps
	LANGUAGES CXX
)

qt5_add_resources(RCC_FILES
	resources.qrc
)

add_executable(${PROJECT_NAME}
	main.cpp
	${RCC_FILES}
)

if(NOT MSVC)
	target_compile_options(${PROJECT_NAME} PUBLIC "-std=c++11")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
)

qt5_use_modules(${PROJECT_NAME}
	Core Gui Quick OpenGL Widgets
)

target_link_libraries(${PROJECT_NAME}
	schnapps_core schnapps_utils ${QT_LIBRARIES}
)
