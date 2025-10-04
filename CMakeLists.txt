cmake_minimum_required(VERSION 3.15)

project(JSEngineTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core Widgets Qml QJSEngine REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Qml)
find_package(Qt5 5.15 REQUIRED COMPONENTS Core Widgets Qml REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(JSEngineTest
    ${PROJECT_SOURCES}
    app.h
    network.h
    input.h
    input.cpp
    settings.h settings.cpp
    messagebox.h messagebox.cpp
    console.h console.cpp
    translations.h translations.cpp
    jogging.h jogging.cpp
    network.h network.cpp
    visualizer.h visualizer.cpp
    device.h device.cpp
    program.h program.cpp
    ui.h ui.cpp
    ui.h ui.cpp
    ui/edit.h ui/edit.cpp
    apis.h
)

target_link_libraries(JSEngineTest PRIVATE Qt5::Widgets Qt5::Core Qt5::Qml)
target_link_libraries(JSEngineTest PRIVATE Qt5::Core)

include(GNUInstallDirs)
install(TARGETS JSEngineTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(JSEngineTest)
endif()
