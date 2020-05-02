cmake_minimum_required(VERSION 3.10)

set(PLUGIN_NAME 02_CustomMetaDataPlugin)
project(${PLUGIN_NAME})

set(CMAKE_CXX_STANDARD 14)
set(COMPILE_TIME_FLAGS
 -std=c++14
 -Wall
 -fno-rtti
)
set(LINK_TIME_FLAGS
 -fPIC
)

set(GXX_INCDIR
 $ENV{GXX_INSTALLDIR}/lib/gcc/x86_64-pc-linux-gnu/10.0.0/plugin/include
)

set(INCLUDE_HEADERS
 PluginMetaData.h
)

set(SOURCES
 CustomMetaDataPlugin.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${INCLUDE_HEADERS})

target_compile_options(
 ${PROJECT_NAME}
 PRIVATE
 ${COMPILE_TIME_FLAGS}
)

target_include_directories(
 ${PROJECT_NAME}
 PRIVATE
 ${GXX_INCDIR}
)

target_link_libraries(
 ${PROJECT_NAME}
 PRIVATE
 ${LINK_TIME_FLAGS}
)

