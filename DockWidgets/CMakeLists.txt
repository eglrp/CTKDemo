include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	"D:\\Project\\CTKDemo\\DockWidgets\\include"
	)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

SET(RESOURCES
		dockwidgets.qrc
	)

qt5_add_resources(dockwidgets ${RESOURCES})
# build lib
add_executable(DockWidgets ${HEADER_FILES} ${SRC_FILES} ${dockwidgets})
qt5_use_modules(DockWidgets Core Sql Concurrent Widgets PrintSupport)
target_link_libraries(DockWidgets CTKCore CTKPluginFramework)

