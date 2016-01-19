# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests player_test.cpp player.cpp share.cpp stock-algorithm.h test_algorithm.h)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
