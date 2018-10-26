cmake_minimum_required(VERSION 3.9)
project(MVVM_Example CXX)


find_package(Qt5 COMPONENTS Qml Quick Gui Widgets REQUIRED)

qt5_wrap_cpp(wrap_cpp
  ViewModel/MainViewModel.h
  qmlapplicationviewer/qmlapplicationviewer.h
)

qt5_add_resources(QT_RESOURCES res.qrc)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    qmlapplicationviewer/qmlapplicationviewer.cpp
    ${wrap_cpp}
    ${QT_RESOURCES}
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  qmlapplicationviewer/
  ViewModel/
  Model/
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    Qt5::Qml
    Qt5::Quick
    Qt5::Gui
    Qt5::Widgets
)
