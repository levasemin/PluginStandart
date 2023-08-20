project(PLUGIN_STANDART)

cmake_minimum_required(VERSION 3.25)

file(GLOB standart_lib_src "src/*/*.cpp")
file(GLOB standart_lib_include "include/*/*.hpp")

file(GLOB include_sl "include")

add_library(standart_lib SHARED ${standart_lib_src} ${standart_lib_include})
target_include_directories(standart_lib PUBLIC ${include_sl})