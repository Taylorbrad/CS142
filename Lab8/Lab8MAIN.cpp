// Example program
#include <iostream>
#include <string>
#include <vector>
//#include "Car.h"

using namespace std;

int menu(int selection, double balance);
void showInventory();
double getBalance(double balance);
void buyCar();
void sellCar();
void paintCar();
void loadFile();
void saveFile();

int main()
{
    int selection = 0;
    double balance = 0;
    balance = 10000;
    
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
            return menu(selection, balance);
        }
        else
        {
            menu(selection, balance);
        }
      }
  
  
}
int menu(int selection)
{
    switch (selection)
    {
            

              //MAGIC NUMBRENOS
        case 1:

          break;
        case 2:
            cout << endl << "Current balance is: $" << getBalance(balance) << endl;
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
void showInventory()
{
}
double getBalance(double balance)
{
    return balance;
}
void buyCar()
{
}
void sellCar()
{
}
void paintCar()
{
}
void loadFile()
{
}
void saveFile()
{
}
