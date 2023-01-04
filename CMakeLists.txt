cmake_minimum_required(VERSION 3.5)

project(sudoku VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        matrix/Matrix.h
        matrix/Matrix.cpp
        matrix/MatrixPosition.h
        matrix/MatrixPosition.cpp
        matrix/MatrixValue.h
        matrix/MatrixValue.cpp
        matrix/RandomSet.h
        matrix/RandomSet.cpp
        ui/MainWidget.h
        ui/MainWidget.cpp
        ui/SquareWidget.h
        ui/SquareWidget.cpp
        ui/NumberLabel.h
        ui/NumberLabel.cpp
        ui/MatrixWidget.h
        ui/MatrixWidget.cpp
        ui/NumberEditor.h
        ui/NumberEditor.cpp
        ui/ItemStackedWidget.h
        ui/ItemStackedWidget.cpp
        Sudoku.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sudoku
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET sudoku APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(sudoku SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(sudoku
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(sudoku PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(sudoku PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sudoku)
endif()

target_include_directories(sudoku PRIVATE /home/herbert/swprojekte/codeblocks/lib/ostd/include)

target_link_libraries(sudoku PRIVATE -L/home/herbert/ablage/programme/lib)
target_link_libraries(sudoku PRIVATE libostd.a)
