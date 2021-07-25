# Register an executable - note that one of the translation units must define a
# 'main()' function.
add_executable(calculator
    calculator.m.cpp
    Calculator.cpp
)

# Add current source directory to include paths for private headers.
target_include_directories(calculator
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link executable against 'ctrpp_libMath' library built by this project.
target_link_libraries(
    calculator
    PUBLIC
    myproject_libMath
)