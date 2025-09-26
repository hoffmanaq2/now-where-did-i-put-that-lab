#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"

//ZOMBIES!!!

TEST_CASE("Z - Zero cases: empty string or substring")
{
    REQUIRE(where("", 'a') == -1);            // empty text
    REQUIRE(where("", "a") == -1);            // empty text, substring search
    REQUIRE(where("abc", "") == -1);          // empty substring
}

TEST_CASE("O - One occurrence")
{
    REQUIRE(where("abc", 'b') == 1);          // char found once
    REQUIRE(where("abc", "b") == 1);          // substring found once
}

TEST_CASE("M - Many occurrences (first index returned)")
{
    REQUIRE(where("banana", 'a') == 1);       // first 'a' at index 1
    REQUIRE(where("banana", "na") == 2);      // first "na" at index 2
}

TEST_CASE("B - Boundaries (start/end of string)")
{
    REQUIRE(where("cat", 'c') == 0);          // start boundary char
    REQUIRE(where("cat", "ca") == 0);         // start boundary substring
    REQUIRE(where("hello", 'o') == 4);        // end boundary char
    REQUIRE(where("hello", "lo") == 3);       // end boundary substring
}

TEST_CASE("I - Interfaces (char overload vs string overload)")
{
    string text = "Hello";
    REQUIRE(where(text, 'h') == 0);           // case-insensitive char
    REQUIRE(where(text, "he") == 0);          // case-insensitive substring
}

TEST_CASE("E - Exceptions or edge-like behavior")
{
    REQUIRE(where("hi", "there") == -1);      // substring longer than text
    REQUIRE(where("nope", 'z') == -1);        // char not found
}

TEST_CASE("S - Sample normal cases")
{
    string text = "The quick brown fox";
    REQUIRE(where(text, 'e') == 2);           // from prompt
    REQUIRE(where(text, "quick") == 4);       // from prompt
    REQUIRE(where(text, "quiet") == -1);      // not found
}
