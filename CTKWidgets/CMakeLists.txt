add_executable(WidgetsDemo WIN32
        main.cpp
)
qt5_use_modules(WidgetsDemo Core Gui Widgets OpenGL Xml)
target_link_libraries(WidgetsDemo CTKCore CTKWidgets)