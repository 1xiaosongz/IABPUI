
cmake_minimum_required(VERSION 4.1)
project(IABPUI)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#add_definitions(-DQCUSTOMPLOT_USE_OPENGL)

set(CMAKE_PREFIX_PATH "D:/QT-wenjian/6.5.3/msvc2019_64")
#add_definitions(-DQT_MESSAGELOGCONTEXT)
add_definitions(-DQT_QML_DEBUG)
set(CMAKE_BUILD_TYPE Debug)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(RESOURCE_PARENT_FOLDER "${CMAKE_SOURCE_DIR}/resource")
file(GLOB_RECURSE QRC_FILES "${RESOURCE_PARENT_FOLDER}/*.qrc")
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/ui)
FILE(GLOB_RECURSE UI_FILES ${PROJECT_SOURCE_DIR}/ui/*.ui)
FILE(GLOB_RECURSE HEAD ${PROJECT_SOURCE_DIR}/include/*.h)
FILE(GLOB_RECURSE HEADHPP ${PROJECT_SOURCE_DIR}/include/*.hpp)
FILE(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")


add_executable(IABPUI main.cpp
        ${QRC_FILES}
        ${SOURCE_FILES}
        ${UI_FILES}
        ${HEAD}
        ${HEADHPP}
        src/topbar.cpp
        include/topbar.h
        src/topbar.cpp
        include/topbar.h
        ui/topbar.ui
        src/statusbar.cpp
        include/statusbar.h
        ui/statusbar.ui
        src/homepage.cpp
        include/homepage.h
        ui/homepage.ui
        src/pressurezeroadjustment.cpp
        include/pressurezeroadjustment.h
        ui/pressurezeroadjustment.ui
        src/horizontalreferenceline.cpp
        include/horizontalreferenceline.h
        ui/horizontalreferenceline.ui
        src/logexport.cpp
        include/logexport.h
        ui/logexport.ui
        src/datewidget.cpp
        include/datewidget.h
        ui/datewidget.ui


        #
#        #        src/Homepage.cpp
##        include/Homepage.h
##        ui/Homepage.ui
##        src/topbar.cpp
##        include/topbar.h
##        ui/topbar.ui
##        src/statusbar.cpp
##        include/statusbar.h
##        ui/statusbar.ui
##        src/bottomnavigationbar.cpp
##        include/bottomnavigationbar.h
##        ui/bottomnavigationbar.ui
##        src/waveformseparation.cpp
##        include/waveformseparation.h
##        ui/waveformseparation.ui
##        src/modeselection.cpp
##        include/modeselection.h
##        ui/modeselection.ui
##        src/inflation_deflation_timing.cpp
##        include/inflation_deflation_timing.h
##        ui/inflation_deflation_timing.ui
##        src/balloonvolume.cpp
##        include/balloonvolume.h
##        ui/balloonvolume.ui
##        src/inflationratio.cpp
##        include/inflationratio.h
##        ui/inflationratio.ui
##        src/triggermode.cpp
##        include/triggermode.h
##        ui/triggermode.ui
##        src/blank1.cpp
##        include/blank1.h
##        ui/blank1.ui
##        src/set.cpp
##        include/set.h
##        ui/set.ui
##        src/blank2.cpp
##        include/blank2.h
##        ui/blank2.ui
##        src/alarmsystem.cpp
##        include/alarmsystem.h
##        ui/alarmsystem.ui
##        src/messagemanagement.cpp
##        include/messagemanagement.h
##        ui/messagemanagement.ui
##        src/level1alarm.cpp
##        include/level1alarm.h
##        ui/level1alarm.ui
##        src/readfile.cpp
##        include/readfile.h
##        sendingthread.cpp
##        sendingthread.h
#
#
)
target_link_libraries(IABPUI

        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::PrintSupport
)









#if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    set(DEBUG_SUFFIX)
#    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
#    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
#    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
#            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        endif ()
#    endif ()
#    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif ()
#    foreach (QT_LIB Core)
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach (QT_LIB)
#endif ()



# 定义主资源文件夹路径
#set(RESOURCE_PARENT_FOLDER "${CMAKE_SOURCE_DIR}/Resource")
#
## 获取Resource文件夹下的所有内容
#file(GLOB ALL_CONTENT "${RESOURCE_PARENT_FOLDER}/*")
#
## 创建一个空的变量来保存所有资源文件
#set(ALL_RESOURCES)
#
## 遍历每个子文件夹
#foreach(CONTENT_PATH ${ALL_CONTENT})
#    if(IS_DIRECTORY ${CONTENT_PATH})
#        # 获取子文件夹的相对路径
#        file(RELATIVE_PATH RESOURCE_FOLDER ${CMAKE_SOURCE_DIR} ${CONTENT_PATH})
#
#        # 获取文件夹名称作为.qrc文件名的一部分
#        get_filename_component(FOLDER_NAME ${RESOURCE_FOLDER} NAME)
#
#        # 查找文件夹中的所有png文件
#        file(GLOB PNG_FILES "${CONTENT_PATH}/*.png")
#
#        # 生成.qrc内容
#        set(QRC_CONTENT "<RCC>\n    <qresource prefix=\"/${FOLDER_NAME}\">\n")
#
#        foreach(PNG_FILE ${PNG_FILES})
#            # 获取文件名（去掉路径）
#            get_filename_component(PNG_FILENAME ${PNG_FILE} NAME)
#            set(QRC_CONTENT "${QRC_CONTENT}        <file>${PNG_FILENAME}</file>\n")
#        endforeach()
#
#        set(QRC_CONTENT "${QRC_CONTENT}    </qresource>\n</RCC>")
#
#        # 设置.qrc文件路径
#        set(QRC_FILE "${CONTENT_PATH}/${FOLDER_NAME}.qrc")
#
#        # 写入.qrc文件
#        file(WRITE "${QRC_FILE}" "${QRC_CONTENT}")
#
#        # 输出生成的.qrc文件路径
#        message(STATUS "Generated ${FOLDER_NAME}.qrc at ${QRC_FILE}")
#
#        # 添加这个.qrc文件到资源列表
#        list(APPEND ALL_RESOURCES ${QRC_FILE})
#    endif()
#endforeach()
