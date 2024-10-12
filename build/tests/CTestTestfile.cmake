# CMake generated Testfile for 
# Source directory: /workspaces/OS_L/tests
# Build directory: /workspaces/OS_L/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lab1_test "/workspaces/OS_L/build/tests/lab1_test")
set_tests_properties(lab1_test PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OS_L/tests/CMakeLists.txt;27;add_test;/workspaces/OS_L/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
