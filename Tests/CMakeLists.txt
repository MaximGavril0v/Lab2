add_subdirectory(D:/C_Projects/Lab2/googletest-master [binary_dir])
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Tests LinkedListTests.cpp DynamicArrayTests.cpp ArraySequenceTests.cpp ListSequenceTests.cpp StackTests.cpp)
target_link_libraries(Tests gtest gtest_main)