project(mbTest)
cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRCS
    main.cpp
    mainwindow.cpp
    )

set(QRCS
    mainwindow.ui
    )

add_executable(${PROJECT_NAME} ${SRCS} ${QRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mb/include)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/mb/bin/
    DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(${PROJECT_NAME}  Qt5::Core Qt5::Widgets Qt5::Gui)
