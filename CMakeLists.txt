cmake_minimum_required(VERSION 3.15)
project(JSEngineTest VERSION 0.1 LANGUAGES CXX C)

# --- Debug build domyślny ---
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

# --- Precompiled headers (PCH) ---
# Użyj najczęściej dołączanych nagłówków Qt
set(PCH_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)  # stwórz plik pch.h z np. #include <QtWidgets>
# PCH będzie użyte w bibliotekach i exe

# --- Lua ---
set(LUA_SRC
    lua/src/lapi.c
    lua/src/lauxlib.c
    lua/src/lbaselib.c
    lua/src/lcode.c
    lua/src/lctype.c
    lua/src/lcorolib.c
    lua/src/ldblib.c
    lua/src/ldebug.c
    lua/src/ldo.c
    lua/src/ldump.c
    lua/src/lfunc.c
    lua/src/lgc.c
    lua/src/linit.c
    lua/src/llex.c
    lua/src/lmathlib.c
    lua/src/lmem.c
    lua/src/loadlib.c
    lua/src/lobject.c
    lua/src/lopcodes.c
    lua/src/loslib.c
    lua/src/lparser.c
    lua/src/lstate.c
    lua/src/lstring.c
    lua/src/lstrlib.c
    lua/src/ltable.c
    lua/src/ltablib.c
    lua/src/ltm.c
    lua/src/lundump.c
    lua/src/lutf8lib.c
    lua/src/lvm.c
    lua/src/lzio.c
    lua/src/liolib.c
)
add_library(lua STATIC ${LUA_SRC})
set_target_properties(lua PROPERTIES AUTOMOC OFF AUTOUIC OFF AUTORCC OFF POSITION_INDEPENDENT_CODE ON)
target_include_directories(lua PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua/src)
set_target_properties(lua PROPERTIES POSITION_INDEPENDENT_CODE ON)

# --- code_editor ---
set(CODE_EDITOR_SRC
    code_editor/src/Widgets/QCodeEditor.cpp
    code_editor/src/Widgets/QCodeEditorEvents.cpp
    code_editor/src/Widgets/QCodeEditorHighlighter.cpp
    code_editor/src/Widgets/QCodeEditorLineWidget.cpp
    code_editor/src/Widgets/QCodeEditorPopup.cpp
    code_editor/src/Widgets/QCodeEditorSlots.cpp
    code_editor/src/Design/QCodeEditorDesign.cpp
    code_editor/src/Design/QCodeEditorSheets.cpp
    code_editor/src/Design/QLineColumnPadding.cpp
    code_editor/src/Design/QSyntaxRule.cpp
    code_editor/src/Design/XmlHelper.cpp
)

# Nagłówki z Q_OBJECT (Automoc potrzebuje ich w targetcie)
set(CODE_EDITOR_HDR
    code_editor/include/KGL/Widgets/QCodeEditor.hpp
    code_editor/include/KGL/Widgets/QCodeEditorHighlighter.hpp
    code_editor/include/KGL/Widgets/QCodeEditorLineWidget.hpp
    code_editor/include/KGL/Widgets/QCodeEditorPopup.hpp
    code_editor/include/KGL/Design/QCodeEditorDesign.hpp
    code_editor/include/KGL/Design/QCodeEditorSheets.hpp
    code_editor/include/KGL/Design/QLineColumnPadding.hpp
    code_editor/include/KGL/Design/QSyntaxRule.hpp
    code_editor/include/KGL/Design/XmlHelper.hpp
)
add_library(code_editor STATIC ${CODE_EDITOR_SRC} ${CODE_EDITOR_HDR})
set_target_properties(code_editor PROPERTIES AUTOMOC ON AUTOUIC ON AUTORCC OFF POSITION_INDEPENDENT_CODE ON)
target_include_directories(code_editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code_editor/include)
target_link_libraries(code_editor PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)
target_precompile_headers(code_editor PUBLIC ${PCH_HEADER})

# --- sol ---
set(SOL_SRC
    sol/config.hpp
    sol/forward.hpp
    sol/sol.hpp
)
add_library(sol INTERFACE ${SOL_SRC})
set_target_properties(lua PROPERTIES AUTOMOC OFF AUTOUIC OFF AUTORCC OFF POSITION_INDEPENDENT_CODE ON)
target_include_directories(sol INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sol)

# --- Main library ---
add_library(pluginengine STATIC
    engine.h engine.cpp
    engine/js.cpp
    engine/lua.cpp
    app.h input.h input.cpp
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
)
target_include_directories(pluginengine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lua/src
    ${CMAKE_CURRENT_SOURCE_DIR}/sol
    ${CMAKE_CURRENT_SOURCE_DIR}/code_editor/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(pluginengine PRIVATE lua sol code_editor Qt5::Widgets Qt5::Core Qt5::Qml Qt5::UiTools)
target_precompile_headers(pluginengine PUBLIC ${PCH_HEADER})

# --- Main executable ---
add_executable(JSEngineTest
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    engine.h engine.cpp
    engine/js.cpp
    engine/lua.cpp
    app.h input.h input.cpp
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
)
target_include_directories(JSEngineTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lua/src
    ${CMAKE_CURRENT_SOURCE_DIR}/sol
    ${CMAKE_CURRENT_SOURCE_DIR}/code_editor/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(JSEngineTest PRIVATE lua sol code_editor Qt5::Widgets Qt5::Core Qt5::Qml Qt5::UiTools)
target_precompile_headers(JSEngineTest PUBLIC ${PCH_HEADER})

# --- Qt6 finalization (opcjonalnie) ---
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(JSEngineTest)
endif()
