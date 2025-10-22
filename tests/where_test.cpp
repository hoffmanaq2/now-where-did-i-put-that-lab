#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"
//ZOMBIES!!!

TEST_CASE("Z - Zero cases: empty string or substring")
{
    REQUIRE(where("", 'a') == -1);              // empty text
    REQUIRE(where("", "a") == -1);              // empty text, substring search
    REQUIRE(where("abc", "") == -1);            // empty substring
}

TEST_CASE("O - One occurrence")
{
    REQUIRE(where("abc", 'b') == 1);            // char found once
    REQUIRE(where("abc", "b") == 1);            // substring found once
}

TEST_CASE("M - Many occurrences (first index returned)")
{
    REQUIRE(where("banana", 'a') == 1);         // first 'a' at index 1
    REQUIRE(where("banana", "na") == 2);        // first "na" at index 2
}

TEST_CASE("B - Boundaries (start/end/starting position)")
{
    string text = "The quick brown fox";

    // Normal boundary tests
    REQUIRE(where("cat", 'c') == 0);            // start of string
    REQUIRE(where("cat", "ca") == 0);           // start substring
    REQUIRE(where("hello", 'o') == 4);          // end of string
    REQUIRE(where("hello", "lo") == 3);         // end substring

    // Starting position behavior
    REQUIRE(where(text, 'e', true, 0) == 2);    // 'e' at index 2
    REQUIRE(where(text, 'e', true, 1) == 2);    // still 2
    REQUIRE(where(text, 'e', true, 2) == 2);    // exact position
    REQUIRE(where(text, 'e', true, 3) == -1);   // no 'e' after index 3
    REQUIRE(where(text, 'e', true, 500) == -1); // out of bounds
}

TEST_CASE("I - Interfaces (char vs string, case sensitivity)")
{
    string text = "The Quick Brown Fox";

    // Case-sensitive (default)
    REQUIRE(where(text, 'q') == -1);            // lowercase not found
    REQUIRE(where(text, "quick") == -1);

    // Case-insensitive
    REQUIRE(where(text, 'q', false) == 4);      // uppercase/lowercase ignored
    REQUIRE(where(text, "quick", false) == 4);
}

TEST_CASE("E - Exceptions or edge-like behavior")
{
    REQUIRE(where("hi", "there") == -1);        // substring longer than text
    REQUIRE(where("nope", 'z') == -1);          // char not found
    REQUIRE(where("abc", 'a', true, -5) == -1); // invalid negative start
    REQUIRE(where("abc", 'a', true, 10) == -1); // invalid large start
}

TEST_CASE("S - Sample normal cases")
{
    string text = "The quick brown fox";

    REQUIRE(where(text, 'e') == 2);             // from prompt
    REQUIRE(where(text, "quick") == 4);         // from prompt
    REQUIRE(where(text, "quiet") == -1);        // not found

    // case-insensitive
    REQUIRE(where(text, "THE", false) == 0);    // ignoring case
}