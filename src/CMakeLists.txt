add_executable(
        MIPS
        main.cpp
        component.cpp
        gate.cpp
)

target_include_directories(MIPS PUBLIC ${CMAKE_SOURCE_DIR}/include)
