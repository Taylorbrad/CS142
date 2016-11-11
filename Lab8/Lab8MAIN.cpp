// Example program
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//#include "Car.h"

using namespace std;

int menu(int selection, double balance, vector<Car> currentInventory);
void showInventory(vector<Car> currentInventory);
double getBalance(double balance);
void buyCar(vector<Car> currentInventory, double& balance);
void sellCar(vector<Car> currentInventory);
void paintCar(vector<Car> currentInventory);
void loadFile();
void saveFile();

int main()
{
    int selection = 0;
    double balance = 0;
    balance = 10000;
    vector<Car> currentInventory;
    
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
int menu(int selection, double balance, vector<Car> currentInventory)
{
    switch (selection)
    {
            

              //MAGIC NUMBRENOS
        case 1:
            showInventory(currentInventory)
          break;
        case 2:
            cout << endl << "Current balance is: $" << getBalance(balance) << endl << endl;
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
void showInventory(vector<Car> currentInventory)
{
    cout << endl << "--------Current Inventory--------" << endl << endl;
    for (int i = 0; i < currentInventory.size(); ++i)
    {
        cout << currentInventory[i].toString();
    }
}
double getBalance(double balance)
{
    return balance;
}
void buyCar(vector<Car> currentInventory, double& balance)
{
    string nameOfCar = "";
    string colorOfCar = "";
    double priceOfCar = 0;
    
    cout << "name of caeerrr" << endl;
    cin >> nameOfCar;
    cout << "color" << endl;
    cin >> colorOfCar;
    cout << "price is right" << endl;
    cin >> priceOfCar;

    if (balance >= priceOfCar)
    {
        Car newCar = Car(nameOfCar, colorOfCar, priceOfCar);
        currentInventory.push_back(newCar);
        balance -= priceOfCar;
    }
    else
    {
        cout << endl << "Car is too expensive!" << endl << endl;
    }
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
