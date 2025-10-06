cmake_minimum_required(VERSION 3.15)

project(JSEngineTest VERSION 0.1 LANGUAGES CXX C)

# --- Debug build szybszy ---
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Qt ---
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 5.15 REQUIRED COMPONENTS Core Widgets Qml UiTools)

# --- Lua ---
file(GLOB LUA_CORE
    lua/src/lapi.c
    lua/src/lparser.c
    lua/src/loadlib.c
    lua/src/lauxlib.c
    lua/src/lcode.c
    lua/src/lctype.c
    lua/src/ldo.c
    lua/src/ldump.c
    lua/src/lundump.c
    lua/src/ldebug.c
    lua/src/lfunc.c
    lua/src/ltm.c
    lua/src/lgc.c
    lua/src/llex.c
    lua/src/lmem.c
    lua/src/lobject.c
    lua/src/lopcodes.c
    lua/src/lstate.c
    lua/src/lstring.c
    lua/src/ltable.c
    lua/src/lvm.c
    lua/src/lzio.c
)

file(GLOB LUA_LIBS
    lua/src/lbaselib.c
    lua/src/lbitlib.c
    lua/src/lcorolib.c
    lua/src/ldblib.c
    lua/src/liolib.c
    lua/src/lmathlib.c
    lua/src/loslib.c
    lua/src/lstrlib.c
    lua/src/ltablib.c
    lua/src/lutf8lib.c
)

add_library(lua STATIC ${LUA_CORE} ${LUA_LIBS})
target_include_directories(lua PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua/src)
set_target_properties(lua PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# --- code_editor ---
file(GLOB_RECURSE CODE_EDITOR_SRC
    code_editor/src/*.cpp
    code_editor/include/*.h
)

add_library(code_editor STATIC ${CODE_EDITOR_SRC})
set_target_properties(code_editor PROPERTIES AUTOMOC ON AUTOUIC OFF AUTORCC OFF)
target_include_directories(code_editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code_editor/include)
target_link_libraries(code_editor PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)
set_target_properties(code_editor PROPERTIES POSITION_INDEPENDENT_CODE ON)

# --- Main executable ---
add_executable(JSEngineTest
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    engine.h engine.cpp
    engine/js.cpp
    engine/lua.cpp
    app.h
    input.h input.cpp
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
    ui/edit.h ui/edit.cpp
    apis.h
    sol/config.hpp sol/forward.hpp sol/sol.hpp
)

# --- Linkowanie ---
target_link_libraries(JSEngineTest
    PRIVATE
        lua
        code_editor
        Qt5::Widgets
        Qt5::Core
        Qt5::Qml
        Qt5::UiTools
)

# --- Include directories ---
target_include_directories(JSEngineTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lua/src
    ${CMAKE_CURRENT_SOURCE_DIR}/code_editor/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# --- Qt6 finalization (opcjonalnie) ---
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(JSEngineTest)
endif()

# --- Równoległe budowanie w Ninja lub Make ---
# Przy budowaniu w Qt Creator lub z CLI:
# cmake --build build -j8
