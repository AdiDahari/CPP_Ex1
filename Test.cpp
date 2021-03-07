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

TEST_CASE("Good snowman code") //HNLRXYTB
{
    //General Tests for valid inputs and expected outcome string.
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

TEST_CASE("Bad snowman code") //HNLRXYTB
{
    //Tests for invalid inputs in each index of the input(0-7).
    CHECK_THROWS(snowman(11111110));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111611));
    CHECK_THROWS(snowman(11117111));
    CHECK_THROWS(snowman(11181111));
    CHECK_THROWS(snowman(11911111));
    CHECK_THROWS(snowman(10111111));
    CHECK_THROWS(snowman(51111111));

    //Tests for inputs not in range.
    CHECK_THROWS(snowman(44444445));
    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(00000000));

    //Tests for invalid length input.
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(1211));
    CHECK_THROWS(snowman(011111111));
    CHECK_THROWS(snowman(000011111111));
}

//Tests for different Hats input.
TEST_CASE("Snowman's Hat") //HNLRXYTB
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("___\n(_*_)\n(.,.)\n( : )\n( : )"));
}

//Tests for different Noses input.
TEST_CASE("Snowman's Nose") //HNLRXYTB
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
}

//Tests for different Left Eyes input.
TEST_CASE("Snowman's Left Eye") //HNLRXYTB
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
}

//Tests for different Right Eyes input.
TEST_CASE("Snowman's Right Eye") //HNLRXYTB
{
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
}

//Tests for different Left Arms input.
TEST_CASE("Snowman's Left Arm") //HNLRXYTB
{
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

//Tests for different Right Arms input.
TEST_CASE("Snowman's Right Arm") //HNLRXYTB
{
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

//Tests for different Torsos input.
TEST_CASE("Snowman's Torso") //HNLRXYTB
{
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144421)) == nospaces("_===_\n(.,-)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11144431)) == nospaces("_===_\n(.,-)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11144441)) == nospaces("_===_\n(.,-)\n(   )\n( : )"));
}

//Tests for different Bases input.
TEST_CASE("Snowman's Base") //HNLRXYTB
{
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144412)) == nospaces("_===_\n(.,-)\n( : )\n(\" \")"));
    CHECK(nospaces(snowman(11144413)) == nospaces("_===_\n(.,-)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11144414)) == nospaces("_===_\n(.,-)\n( : )\n(   )"));
}