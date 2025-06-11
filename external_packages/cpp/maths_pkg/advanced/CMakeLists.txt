# Create the library
add_library(math_advanced SHARED src/multiply.cpp src/divide.cpp )

# Link the includes
target_include_directories(math_advanced PUBLIC include )

# Install instructions
install(TARGETS math_advanced DESTINATION lib)
install(DIRECTORY include/advanced DESTINATION include)