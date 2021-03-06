cmake_minimum_required(VERSION 3.1)

project(iota-ledger-test C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

enable_testing()

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

find_package(CMocka REQUIRED)
include_directories(${CMOCKA_INCLUDE_DIR})

include_directories(
    "../src"
    "../src/iota"
    "../src/keccak"
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow")

# enable compilation on host
add_definitions(
    -DNO_BOLOS
    -DTEST_FOLDER="${CMAKE_SOURCE_DIR}/kerl-spec/test_vectors"
)

add_library(iota-ledger SHARED
    "../src/iota/addresses.c"
    "../src/iota/conversion.c"
    "../src/iota/kerl.c"
    "../src/keccak/sha3.c"
    "../src/aux.c"
)

add_executable(conversion_test conversion_test.c)
target_link_libraries(conversion_test ${CMOCKA_LIBRARIES} iota-ledger)
add_test(conversion_test ${CMAKE_CURRENT_BINARY_DIR}/conversion_test)

add_executable(kerl_test kerl_test.c hash_file.c)
target_link_libraries(kerl_test ${CMOCKA_LIBRARIES} iota-ledger)
add_test(kerl_test ${CMAKE_CURRENT_BINARY_DIR}/kerl_test)

add_executable(address_test address_test.c hash_file.c)
target_link_libraries(address_test ${CMOCKA_LIBRARIES} iota-ledger)
add_test(address_test ${CMAKE_CURRENT_BINARY_DIR}/address_test)
