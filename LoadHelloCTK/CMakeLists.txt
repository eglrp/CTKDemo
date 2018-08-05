include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	"D:\\project\\CTKDemo\\BlogManagerPlugin\\include"
	)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


# build lib
add_executable(LoadHelloCTK ${HEADER_FILES} ${SRC_FILES})
qt5_use_modules(LoadHelloCTK Core Sql Concurrent Widgets)
target_link_libraries(LoadHelloCTK CTKCore CTKPluginFramework)

