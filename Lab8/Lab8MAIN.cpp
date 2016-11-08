// Example program
#include <iostream>
#include <string>
#include <vector>
//#include "Car.h"

using namespace std;

int menu(int selection);

int main()
{
    int selection = 0;
    while (1 == 1)
    {
        cout << "1 - Show Current Inventory" << endl;
        cout << "2 - Show Current Ballance" << endl;
        cout << "3 - Buy a Car" << endl;
        cout << "4 - Sell a Car" << endl;
        cout << "5 - Paint a Car" << endl;
        cout << "6 - Load File" << endl;
        cout << "7 - Save File" << endl;
        cout << "8 - Quit Program" << endl;
        cout << "Selection: ";
        cin >> selection;
        
        if (selection == 8)
        {
            return menu(selection);
        }
        else
        {
            menu(selection);
        }
      }
  
  
}
int menu(int selection)
{
      switch (selection)
      {
            case 1:
              
              break;
            case 2:
              
              break;
            case 3:
              
              break;
            case 4:
              
              break;
            case 5:
              
              break;
            case 6:
              
              break;
            case 7:
              
              break;
            case 8:
              
              return 0;
              break;
      }
}
