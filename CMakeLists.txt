cmake_minimum_required(VERSION 3.11)

project(AnggurSandbox)

add_subdirectory(Vendor/Anggur)

add_executable(AnggurSandbox Source/EntryPoint.cpp)

target_link_libraries(AnggurSandbox Anggur)
