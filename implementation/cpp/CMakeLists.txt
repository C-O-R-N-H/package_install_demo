# need to run this
# sudo ldconfig  # updates library cache

# can run:
# g++ test.cpp -o test_cpp -lmath_basic -lmath_advanced # build cpp file
# or build with this

cmake_minimum_required(VERSION 3.14)
project(math_pkg_test)


add_executable(run_test src/test.cpp)
target_link_libraries(run_test math_basic math_advanced)