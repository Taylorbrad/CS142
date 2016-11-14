// Example program
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
//#include "Car.h"

using namespace std;

int menu(int selection, double balance, vector<Car> currentInventory);
void showInventory(vector<Car> currentInventory);
double getBalance(double balance);
void buyCar(vector<Car> currentInventory, double& balance);
void sellCar(vector<Car> currentInventory, double& balance);
void paintCar(vector<Car> currentInventory);
void loadFile(vector<Car> currentInventory, double& balance);
void saveFile(vector<Car> currentInventory, double balance);

const int SHOW_INVENTORY = 1;
const int SHOW_BALANCE = 2;
const int BUY_CAR = 3;
const int SELL_CAR = 4;
const int PAINT_CAR = 5;
const int LOAD_FILE = 6;
const int SAVE_FILE = 7;
const int QUIT = 8;
    
int main()
{
    int selection = 0;
    double balance = 0;
    balance = 10000;
    vector<Car> currentInventory;
    
    while (true)
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
        
        if (selection == QUIT)
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
        case SHOW_INVENTORY:
            showInventory(currentInventory)
          break;
        case SHOW_BALANCE:
            cout << endl << "Current balance is: $" << getBalance(balance) << endl << endl;
          break;
        case BUY_CAR:
            buyCar(currentInventory, balance);
          break;
        case SELL_CAR:
            sellCar(currentInventory, balance);
          break;
        case PAINT_CAR:
            paintCar(currentInventory);
          break;
        case LOAD_FILE:
            loadFile(currentInventory, balance);
          break;
        case SAVE_FILE:
            saveFile(currentInventory, balance);
          break;
        case QUIT:

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
void sellCar(vector<Car> currentInventory, double& balance)
{
    string carToFind = "";
    
    cout << "Which car would you like to sell?" << endl;
    cin >> carToFind;
    
    for (int i = 0; i < currentInventory.size(); ++i)
    {
        if (carToFind == currentInventory[i].name)
        {
            //sell commands
        }
    }
}
void paintCar(vector<Car> currentInventory)
{
    string carToFind = "";
    string newColor = "";
    
    cout << "Which car would you like to paint?" << endl;
    cin >> carToFind;
    
    for (int i = 0; i < currentInventory.size(); ++i)
    {
        if (carToFind == currentInventory[i].name)
        {
            cout << "What color would you like to paint the car?" << endl;
            cin >> newColor;
            
            currentInventory[i].paint(newColor);
            
            cout << "Car successfully painted!" << endl;
        }
    }
    if (newColor == "")
    {
        cout << "Car name not found."; << endl;
    }
}
void loadFile(vector<Car> currentInventory, double& balance)
{
    string fileToOpen = "";
    string balanceString = "";
    string carName = "";
    string carColor = "";
    string carPrice = "";
    double priceDouble = 0;
    ifstream inFile;
    
    cout << "what file would you like to open?";
    cin >> fileToOpen;
    
    inFile.open(fileToOpen, ios::out);
    if (inFile.is_open())
    {
        //code to write file to new cars in vector
        
        getline(inFile, salaryString);
        balance += atof(balanceString.c_str());
        
        for (int i = 0; i < currentInventory.size(); ++i)
        {
            getline(inFile, carName, " ");
            getline(inFile, carColor, " ");
            getline(inFile, carPrice);
            
            priceDouble = atof(carPrice.c_str());
            Car newCar = Car(carName, carColor, priceDouble);
            currentInventory.push_back(newCar);
        }
    }
}
void saveFile(vector<Car> currentInventory, double balance)
{
    ofstream outFile;
    string fileToOpen = "";
    
    cout << "What would you like the file to be called?";
    cin >> fileToOpen;
    
    outFile.open(fileToOpen, ios::app);
    if (outFile.is_open())
    {
        outFile << balance << endl;
        for (int i = 0; i < currentInventory.size(); ++i)
        {
            outFile << currentInventory[i].name << " " << currentInventory[i].color << " " << currentInventory[i].price << endl;
        }
        cout << "File successfully created!" << endl;
    }
    else
    {
        cout << "Error writing to file: " << fileToOpen << endl;
    }
}
