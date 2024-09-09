cmake_minimum_required(VERSION 3.30.3)
project(ProjectName)

add_executable(main
  main.cpp
)

find_package(viam-cpp-sdk REQUIRED viamsdk)

target_link_libraries(main viam-cpp-sdk::viamsdk)

# Uncomment the line below if there are issues with the C++ standard, or if you want to set it
# explicitly for this project.

# target_compile_features(main cxx_std_17)
