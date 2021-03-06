#include "snowman.hpp"
#include <iostream>
#include <string>
#include <exception>
//As required - namespace ariel is used for the function snowman
namespace ariel
{

    //Function which returns a string with the desired snowman's components. recieves an int as a parameter.
    string snowman(int input)
    {

        //Duplicating the input for validating correctness.
        int check = input;

        //1st validation for not accepting unhandled inputs. Exception thrown if input isn't valid.
        if (input < 11111111 || input > 44444444)
        {
            std::__throw_invalid_argument("Not a valid input!");
        }
        else
        {
            //2nd validation using the check int for not accepting numbers in [11111111 - 44444444] which contains any number except [1-4](such as 11115011).
            for (int i = 0; i < 8; i++)
            {
                if (check % 10 > 4 || check % 10 < 1)
                {
                    std::__throw_invalid_argument("Not a valid input!");
                }
                check /= 10;
            }

            //Creating strings arrays for easy access to each component needed in each scenario.
            const string hat[] = {"", "_===_\n", " ___ \n .....\n", "  _  \n  /_\\ \n", " ___ \n (_*_)\n"};
            const string nose[] = {"", ",", ".", "_", " "};
            const string lEye[] = {"", ".", "o", "O", "-"};
            const string rEye[] = {"", ".", "o", "O", "-"};
            const string highLA[] = {"", " ", "\\", " ", " "};
            const string lowLA[] = {"", "<", " ", "/", " "};
            const string highRA[] = {"", " ", "/", " ", " "};
            const string lowRA[] = {"", ">", " ", "\\", " "};
            const string torso[] = {"", " : ", "] [", "> <", "   "};
            const string base[] = {"", " : ", "\" \"", "___", "   "};

            //Converting the input int to an array for easy access each component seprately.
            int *arr = new int[8];
            for (int i = 7; i >= 0; i--)
            {
                arr[i] = input % 10;
                input /= 10;
            }

            /**Building the desired string by given input in the desired template:
             *  HHHHH
             *  HHHHH  = H for Hat.
             * X(LNR)Y = X for upper-left Arm, L for Left Eye, N for Nose, R for Right Eye, Y for upper-left Arm. 
             * X(TTT)Y = X for lower-right Arm, T for Torso, Y for lower-right Arm.
             *  (BBB)  = B for Base.
             * */
            string ans = " " + hat[arr[0]] + highLA[arr[4]] + "(" + lEye[arr[2]] + nose[arr[1]] + rEye[arr[3]] + ")" + highRA[arr[5]] + "\n" + lowLA[arr[4]] + "(" + torso[arr[6]] + ")" + lowRA[arr[5]] + "\n (" + base[arr[7]] + ")";
            return ans;
        }
    }
}

// int main()
// {
//     std::cout << ariel::snowman(11111120) << endl;
// }
