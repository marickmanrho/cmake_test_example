enable_testing()

# Add tests in subdirectories
add_subdirectory("MathFunctions")

# Basic test to see if NISE runs
add_test(NAME Runs COMMAND NISE 5)