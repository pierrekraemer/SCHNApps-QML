add_subdirectory(core)

project(schnapps_app
	LANGUAGES CXX
)

add_executable(schnapps
	main.cpp
)

qt5_use_modules(schnapps
	Core Gui OpenGL Xml Svg Widgets
)
target_link_libraries(schnapps
	schnapps_core ${QT_LIBRARIES} # PythonQt ${PYTHON_LIBRARIES}
)
