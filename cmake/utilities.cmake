
#!
# @brief automatic deduction of CMAKE_BUILD_TYPE from CMAKE_CURRENT_BINARY_DIR
# @details
# if CMAKE_CURRENT_BINARY_DIR end with Debug/debug/DEBUG, set Debug mode else Release mode.
#
function(setBuildType)
IF (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug|Release"))
	IF (${CMAKE_CURRENT_BINARY_DIR} MATCHES "(.*)Debug|(.*)debug|(.*)DEBUG")
		SET(CMAKE_BUILD_TYPE "Debug" PARENT_SCOPE)
	ELSE()
		SET(CMAKE_BUILD_TYPE "Release" PARENT_SCOPE)
	ENDIF()
ENDIF()
endfunction(setBuildType)
