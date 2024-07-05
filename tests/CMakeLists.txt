enable_testing()

add_executable(
        mips_test

        test_gate.cpp
        test_latch.cpp

        ${CMAKE_SOURCE_DIR}/src/component.cpp
        ${CMAKE_SOURCE_DIR}/src/gate.cpp
        ${CMAKE_SOURCE_DIR}/src/latch.cpp
)

target_include_directories(mips_test PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(
        mips_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mips_test)
