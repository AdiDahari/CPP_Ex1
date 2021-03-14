#include "snowman.hpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    cout << ariel::snowman(11111111) << endl; /*Should Print:
 _===_
 (.,.) 
<( : )>
 ( : ) */
    cout << ariel::snowman(22222222) << endl; /*Should Print:
  ___ 
 .....
\(o.o)/
 (] [) 
 (" ") */
    cout << ariel::snowman(33333333) << endl; /*Should Print:
   _  
  /_\ 
 (O_O) 
/(> <)\
 (___) */
    cout << ariel::snowman(44444444) << endl; /*Should Print:
  ___ 
 (_*_)
 (- -) 
 (   ) 
 (   ) */
    cout << ariel::snowman(32143121) << endl; /*Should Print:
   _  
  /_\ 
 (..-) 
/(] [)>
 ( : ) */
    cout << ariel::snowman(33232124) << endl; /*Should Print:
   _
  /_\
\(o_O)
 (] [)>
 (   ) */
    cout << ariel::snowman(32221133) << endl; /*Should Print:
   _  
  /_\ 
 (o.o) 
<(> <)>
 (___) */
}