#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dynamic_array.hpp"

TEST_CASE("push_back and size work") {
    IntDynamicArray arr;
    arr.push_back(5);
    arr.push_back(10);

    REQUIRE(arr.size() == 2);
    REQUIRE(arr.at(0) == 5);
    REQUIRE(arr.at(1) == 10);
}

TEST_CASE("single element") {
    IntDynamicArray arr;
    arr.push_back(42);

    REQUIRE(arr.size() == 1);
    REQUIRE(arr.at(0) == 42);
}

