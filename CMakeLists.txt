cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(KeyLogger VERSION 0.1.0)

include(FetchContent)
include(CTest)
enable_testing()

set(FETCHCONTENT_QUIET OFF)


# spdlog
# FetchContent_Declare(
#     spdlog
#     GIT_REPOSITORY https://github.com/gabime/spdlog.git
#     )
    
# FetchContent_GetProperties(spdlog)
    
# if(NOT spdlog_POPULATED)
#     FetchContent_Populate(spdlog)
#     add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
# endif()

# inputLite
FetchContent_Declare(
    inputLite
    GIT_REPOSITORY https://github.com/smasherprog/input_lite.git
    )
    
FetchContent_GetProperties(inputLite)
    
if(NOT inputLite_POPULATED)
    FetchContent_Populate(inputLite)
    message("src")
    message(${inputLite_SOURCE_DIR})
    message("bin")
    message(${inputLite_BINARY_DIR})
    add_subdirectory(${inputLite_SOURCE_DIR} ${inputLite_BINARY_DIR})
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(SRC 
    src/main.cpp)

add_executable(KeyLogger ${SRC})

set_target_properties(KeyLogger PROPERTIES
            CXX_STANDARD 14
            CMAKE_CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS OFF
)

target_include_directories(KeyLogger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # ${spdlog_SOURCE_DIR}/include
    )

# target_link_libraries(KeyLogger spdlog)
target_link_libraries(KeyLogger pthread inputLite)

# add_dependencies(KeyLogger spdlog)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/logs")
