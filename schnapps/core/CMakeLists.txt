project(schnapps_core
	LANGUAGES CXX
)

set(HEADER_FILES
	schnapps.h
)

set(SOURCE_FILES
	schnapps.cpp
)

qt_wrap_ui(UIC_FILES
	${SCHNAppsLib_UI_FILES}
)

qt_wrap_cpp(MOC_FILES
	${SCHNAppsLib_QOBJECT_FILES}
)

#qt_add_resources(RCC_FILES
#	${SCHNApps_ROOT_DIR}/resources/resources.qrc
#)

add_library(${PROJECT_NAME} SHARED
	${HEADER_FILES}
	${SOURCE_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CGOGN_SOURCE_DIR}>
)

target_link_libraries(${PROJECT_NAME}
	${QT_LIBRARIES} # PythonQt ${PYTHON_LIBRARIES}
)
