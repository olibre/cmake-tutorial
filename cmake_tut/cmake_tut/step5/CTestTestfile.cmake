# CMake generated Testfile for 
# Source directory: /Users/jinwei/cmake/cmake_tut/step5
# Build directory: /Users/jinwei/cmake/cmake_tut/step5
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TutorialRuns "Tutorial" "25")
add_test(TutorialUsage "Tutorial")
set_tests_properties(TutorialUsage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:.*number")
add_test(TutorialComp4 "Tutorial" "4")
set_tests_properties(TutorialComp4 PROPERTIES  PASS_REGULAR_EXPRESSION "4 is 2")
add_test(TutorialComp9 "Tutorial" "9")
set_tests_properties(TutorialComp9 PROPERTIES  PASS_REGULAR_EXPRESSION "9 is 3")
add_test(TutorialComp5 "Tutorial" "5")
set_tests_properties(TutorialComp5 PROPERTIES  PASS_REGULAR_EXPRESSION "5 is 2.236")
add_test(TutorialComp7 "Tutorial" "7")
set_tests_properties(TutorialComp7 PROPERTIES  PASS_REGULAR_EXPRESSION "7 is 2.645")
add_test(TutorialComp25 "Tutorial" "25")
set_tests_properties(TutorialComp25 PROPERTIES  PASS_REGULAR_EXPRESSION "25 is 5")
add_test(TutorialComp-25 "Tutorial" "-25")
set_tests_properties(TutorialComp-25 PROPERTIES  PASS_REGULAR_EXPRESSION "-25 is 0")
add_test(TutorialComp0.0001 "Tutorial" "0.0001")
set_tests_properties(TutorialComp0.0001 PROPERTIES  PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
subdirs(MathFunctions)
