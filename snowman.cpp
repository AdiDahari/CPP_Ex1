/**
 * This file defines the "ariel" namespace for the assignment.
 * the namespace contains a single function which returns a String representing a modular snowman print.
 * each different input ([1-4], length = 8) returns a different snowman.
 * each input of 8 numbers in [1-4] represents a sequence of compenents: HNLRXYTB
 * (H = Hat, N = Nose, L = Left Eye, R = Right Eye, X = Left Arm, Y = Right Arm, T = Torso, B = Base).
 * Building the desired snowman is creating a string by the template:
 *  HHHHH
 *  HHHHH  = H for Hat.
 * X(LNR)Y = X for upper-left Arm, L for Left Eye, N for Nose, R for Right Eye, Y for upper-left Arm. 
 * X(TTT)Y = X for lower-right Arm, T for Torso, Y for lower-right Arm.
 *  (BBB)  = B for Base.
 * 
 * For more information please visit: https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman .
 * */

#include "snowman.hpp"
#include <iostream>
#include <array>
#include <string>
#include <exception>
using namespace std;

//As required - namespace ariel is used for the function snowman
namespace ariel
{
    enum comp
    {
        H,
        N,
        L,
        R,
        X,
        Y,
        T,
        B

    };

    //Function which returns a string with the desired snowman's components. recieves an int as a parameter.
    string snowman(int input)
    {

        //1st validation for not accepting unhandled inputs. Exception thrown if input isn't valid.
        if (input < MIN_VAL || input > MAX_VAL)
        {
            __throw_invalid_argument("Error! Not a valid input");
        }
        else
        {
            array<int, LEN> arr = {};
            //2nd validation using the check int for not accepting numbers in [11111111 - 44444444] which contains any number except [1-4](such as 11115011).
            for (int i = 0; i < LEN; i++)
            {
                if (input % BASE > 4 || input % BASE < 1)
                {
                    __throw_invalid_argument("Error! Not a valid input");
                }
                arr.at(FINAL_INDEX - i) = input % BASE;
                input /= BASE;
            }

            //Creating strings arrays for easy access to each component needed in each scenario.
            const array<string, 5> hat = {"", "_===_\n", " ___ \n .....\n", "  _  \n  /_\\ \n", " ___ \n (_*_)\n"};
            const array<string, 5> nose = {"", ",", ".", "_", " "};
            const array<string, 5> lEye = {"", ".", "o", "O", "-"};
            const array<string, 5> rEye = {"", ".", "o", "O", "-"};
            const array<string, 5> highLA = {"", " ", "\\", " ", " "};
            const array<string, 5> lowLA = {"", "<", " ", "/", " "};
            const array<string, 5> highRA = {"", " ", "/", " ", " "};
            const array<string, 5> lowRA = {"", ">", " ", "\\", " "};
            const array<string, 5> torso = {"", " : ", "] [", "> <", "   "};
            const array<string, 5> base = {"", " : ", "\" \"", "___", "   "};

            //Converting the input int to an array for easy access each component seprately.

            string ans = " " + hat.at(arr.at(H)) +
                         highLA.at(arr.at(X)) + "(" + lEye.at(arr.at(L)) + nose.at(arr.at(N)) + rEye.at(arr.at(R)) + ")" + highRA.at(arr.at(Y)) + "\n" +
                         lowLA.at(arr.at(X)) + "(" + torso.at(arr.at(T)) + ")" + lowRA.at(arr.at(Y)) + "\n (" +
                         base.at(arr.at(B)) + ")";
            return ans;
        }
    }
}

// int main()
// {
//     std::cout << ariel::snowman(11144414) << endl;
// }
