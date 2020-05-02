cmake_minimum_required(VERSION 3.10)

set(PLUGIN_NAME 00_DummyGxxPlugin)
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

set(SOURCES
  DummyGxxPlugin.cpp
  )

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_compile_options(${PROJECT_NAME}
  PRIVATE
  ${COMPILE_TIME_FLAGS}
  )
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  ${LINK_TIME_FLAGS}
  )

