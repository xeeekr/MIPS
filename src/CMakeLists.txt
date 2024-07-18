add_executable(
        MIPS
        main.cpp
        component.cpp
        gate.cpp
        latch.cpp
        flipflop.cpp
        mux.cpp
)

target_include_directories(MIPS PUBLIC ${CMAKE_SOURCE_DIR}/include)
