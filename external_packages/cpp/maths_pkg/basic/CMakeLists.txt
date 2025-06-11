# Create the library
add_library(math_basic SHARED src/add.cpp src/sub.cpp )

# Link the includes
target_include_directories(math_basic PUBLIC include )

# Install instructions
install(TARGETS math_basic DESTINATION lib)
install(DIRECTORY include/basic DESTINATION include)