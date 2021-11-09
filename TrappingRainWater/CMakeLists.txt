add_executable(
        trapping_rain_water_test
        tests.cpp
        trappingrainwater.cpp
        trappingrainwater.h
)
target_link_libraries(
        trapping_rain_water_test
        gtest_main
)

gtest_discover_tests(trapping_rain_water_test)