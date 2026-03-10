add_executable(keep_tests test_darray.c)
target_link_libraries(keep_tests PRIVATE keep)
add_test(NAME KeepUnitTests COMMAND keep_tests)
