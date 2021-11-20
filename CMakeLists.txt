cmake_minimum_required(VERSION 3.20)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        bf0701daa9f5b30e5882e2f8f9a5280bcba87e77 # release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

add_subdirectory(TrappingRainWater)
add_subdirectory(SlidingWindowMaximum)
add_subdirectory(MissingNumber)
add_subdirectory(KadanesAlgorithm)
add_subdirectory(Towers)
add_subdirectory(NextLargerElement)
add_subdirectory(LongTermProblem)
add_subdirectory(MaxSegmentIntersections)
add_subdirectory(BinarySearchTree)
add_subdirectory(LongestKGoodSegment)
add_subdirectory(MaximumPathSum)
add_subdirectory(FenwickTree)
add_subdirectory(NestedSegments)
add_subdirectory(CountingInversions)
add_subdirectory(SegmentTree)
add_subdirectory(RodCutting)
add_subdirectory(HouseRobber)
