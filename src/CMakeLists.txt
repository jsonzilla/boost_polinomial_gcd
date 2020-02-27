cmake_minimum_required(VERSION 2.8)

project(poly_gcd)
include(gtest.cmake)

# set(COVERAGE OFF CACHE BOOL "Coverage")

#file(GLOB sources "example.cpp")
#file(GLOB headers "example.h")
add_executable(poly_gcd 
    main.cpp 
	"poly.h"
    ${headers}
    ${sources}
    ) 

file(GLOB sourcesTests "unit_fixture.cpp")
file(GLOB headersTests "unit_fixture.h")
add_executable(tests 
    "unit_tests.cpp"
	"poly.h"
    ${headers}
    ${sources} 
    ${headersTests} 
    ${sourcesTests} 
    )

#target_include_directories(poly_gcd)   

#target_include_directories(tests)   

find_package(Boost COMPONENTS filesystem system unit_test_framework chrono date_time REQUIRED)

find_package (Threads)
include_directories(${Boost_INCLUDE_DIRS}) 
target_link_libraries(tests gtest ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})   

if (MSVC)
    target_compile_options(tests PRIVATE /std:c++17)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")

    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
else()
    target_compile_options(poly_gcd PRIVATE -std=c++11 -g -fpermissive)
    target_compile_options(tests PRIVATE -std=c++11 -g -fpermissive)
    # if (COVERAGE)
    #     target_compile_options(tests PRIVATE --coverage)
    #     target_link_libraries(tests PRIVATE --coverage)
    # endif()
endif()




