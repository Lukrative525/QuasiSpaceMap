cmake_minimum_required(VERSION 3.23)
project(QuasiSpaceMap LANGUAGES CXX VERSION 0.1.0)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

# QuasiSpaceMap Library
add_library(QuasiSpaceMapLibrary STATIC)
target_sources(QuasiSpaceMapLibrary
    PRIVATE
        coordinate.cpp
        coordinatehash.cpp
        image.cpp
        imageinstance.cpp
        imageviewer.cpp
        pathplanner.cpp
        pathplannerfunctions.cpp
        starchart.cpp
        starchartdata.cpp
        starsystem.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
            coordinate.h
            coordinatehash.h
            image.h
            imageinstance.h
            imageviewer.h
            pathplanner.h
            pathplannerfunctions.h
            starchart.h
            starchartdata.h
            starsystem.h
)
target_compile_features(QuasiSpaceMapLibrary PUBLIC cxx_std_17)
target_include_directories(QuasiSpaceMapLibrary PRIVATE)
target_link_libraries(QuasiSpaceMapLibrary
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::OpenGLWidgets
)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources.rc")

# QuasiSpaceMap Application
add_executable(QuasiSpaceMap WIN32 ${APP_ICON_RESOURCE_WINDOWS})
target_sources(QuasiSpaceMap
    PRIVATE
        graphicsviewer.cpp
        graphicsviewer.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        resources.qrc
)

target_compile_features(QuasiSpaceMap PUBLIC cxx_std_17)
target_include_directories(QuasiSpaceMap PRIVATE)
target_link_libraries(QuasiSpaceMap
    PRIVATE
        Qt6::OpenGLWidgets
        QuasiSpaceMapLibrary
)
