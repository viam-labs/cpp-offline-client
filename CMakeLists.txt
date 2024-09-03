cmake_minimum_required(VERSION 3.30.3)
project(ProjectName)

add_executable(main
  main.cpp
)

find_package(PkgConfig)

pkg_check_modules(viam REQUIRED viam-cpp-sdk-libviamsdk)

target_link_libraries(main ${viam_LIBRARIES})
target_include_directories(main PUBLIC ${viam_INCLUDE_DIRS})
target_compile_options(main PUBLIC ${viam_CFLAGS_OTHER})
