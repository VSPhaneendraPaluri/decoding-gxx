cmake_minimum_required(VERSION 3.10)

set(SOLUTION GxxPlugins)
project(${SOLUTION})

enable_testing()

add_subdirectory(00_dummy_plugin)
add_subdirectory(01_basic_plugin)
add_subdirectory(02_custom_metadata_plugin)
add_subdirectory(03_plugin_info_by_cb)
add_subdirectory(04_cxx_ast)

