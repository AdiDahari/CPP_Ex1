/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Adi Dahari
 * 
 * Date: 2021-02
 */
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good snowman code")
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
    CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(   )"));
    CHECK(nospaces(snowman(43214321)) == nospaces("___\n(_*_)\n(o_.)\n(] [)\\\n( : )"));
    CHECK(nospaces(snowman(11223344)) == nospaces("_===_\n(o,o)\n/(   )\\\n(   )"));
    CHECK(nospaces(snowman(44332211)) == nospaces("___\n(_*_)\n\\(O O)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(34231234)) == nospaces("_\n/_\\\n(o O)/\n<(> <)\n(   )"));
}

TEST_CASE("Bad snowman code")
{
    CHECK_THROWS(snowman(11111110));
    CHECK_THROWS(snowman(44444445));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(999999999));
    CHECK_THROWS(snowman(12341235));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(1211));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(20154321));
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(44444440));
    CHECK_THROWS(snowman(30111111));
    CHECK_THROWS(snowman(22222220));
    CHECK_THROWS(snowman(40111111));
    CHECK_THROWS(snowman(011111111));
    CHECK_THROWS(snowman(000011111111));
}

/* Add more test cases here */