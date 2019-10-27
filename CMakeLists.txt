cmake_minimum_required (VERSION 2.6)
project (Tutorial)
add_executable(Tutorial t.cpp stdafx.cpp)

enable_testing()
add_executable(unittest linklist2.cpp linklist2_unittest.cpp)
add_test(test unittest)
set_tests_properties (test PROPERTIES PASS_REGULAR_EXPRESSION "1,3")

