# Static libraries are built as '.a' files, and are bundled with the executable.
add_library(myproject_libMath
    STATIC
    Adder.cpp
    Divider.cpp
)

# Set up test target for library.
add_executable(myproject_libMathTest
    Adder.g.cpp
    Divider.g.cpp
)

# Link test target with GoogleTest (included via Conan package manager) and the
# actual library under test.
target_link_libraries(myproject_libMathTest
    PRIVATE
    ${CONAN_LIBS}
    myproject_libMath
)

# Register tests with 'ctest'.
gtest_discover_tests(myproject_libMathTest)