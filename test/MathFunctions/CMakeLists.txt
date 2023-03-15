add_executable(test_square_root test_square_root.cpp)
target_link_libraries(test_square_root PRIVATE MathFunctions)

enable_testing()
add_test(
  NAME test_square_root
  COMMAND test_square_root 7
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp_${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp_${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(test_square_root 4 "4 is 2")
do_test(test_square_root 9 "9 is 3")
do_test(test_square_root 5 "5 is 2.236")
do_test(test_square_root 7 "7 is 2.645")
do_test(test_square_root 25 "25 is 5")
do_test(test_square_root -25 "-25 is (-nan|nan|0)")
do_test(test_square_root 0.0001 "0.0001 is 0.01")