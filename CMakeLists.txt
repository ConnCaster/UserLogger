CMAKE_MINIMUM_REQUIRED(VERSION 3.23)
project(UserLogger)

list(APPEND ${PROJECT}_SOURCES
    sources/user.cpp
    sources/log_session.cpp
)

list(APPEND ${PROJECT}_HEADERS
    "${CMAKE_SOURCE_DIR}/include"
)

add_executable(UserLogger ${${PROJECT}_SOURCES} main.cpp)
target_include_directories(UserLogger PUBLIC ${${PROJECT}_HEADERS})


find_package(GTest REQUIRED PATHS "${CMAKE_SOURCE_DIR}/deps/linux/google_test")
add_executable(tests_google tests/google_tests.cpp ${${PROJECT}_SOURCES})
target_link_libraries(tests_google GTest::gtest_main)
target_include_directories(tests_google PUBLIC "${CMAKE_SOURCE_DIR}/deps/linux/google_test/include" ${${PROJECT}_HEADERS})
target_compile_definitions(tests_google PUBLIC BUILD_GOOGLE_TEST)