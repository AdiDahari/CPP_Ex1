#include "snowman.hpp"
#include <iostream>
#include <string>
#include <exception>

namespace ariel
{
    string snowman(int input)
    {
        int check = input;
        if (input < 11111111 || input > 44444444)
        {
            std::__throw_invalid_argument("Not a valid input!");
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (check % 10 > 4 || check % 10 < 1)
                {
                    std::__throw_invalid_argument("Not a valid input!");
                }
                check /= 10;
            }
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

            int *arr = new int[8];
            for (int i = 7; i >= 0; i--)
            {
                arr[i] = input % 10;
                input /= 10;
            }
            string ans = " " + hat[arr[0]] + highLA[arr[4]] + "(" + lEye[arr[2]] + nose[arr[1]] + rEye[arr[3]] + ")" + highRA[arr[5]] + "\n" + lowLA[arr[4]] + "(" + torso[arr[6]] + ")" + lowRA[arr[5]] + "\n (" + base[arr[7]] + ")";
            return ans;
        }
    }
}

// int main()
// {
//     std::cout << ariel::snowman(11111120) << endl;
// }
