// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;
string getFileName()
{
    string fileName = 0;
    
    cout << "Where should I read the data from? ";
    cin >> fileName;
    
    return fileName;
}
int main()
{
    string fileName = "";
    ifstream toOpen;
    string address = "";
    string typeOfProperty = "";
    double value = 0;
    double discount = 0;
    int id = 0;
    bool isRental = false;
    bool isDiscounted = false;
    bool isOccupied = false;
    
    fileName = getFileName();
    
    toOpen.open("fileName");
    
    if (toOpen.is_open();
    {
        while (!toOpen.eof())
        {
            getline(toOpen, typeOfProperty, ' ');
            getline(toOpen, isRental, ' ';
            getline(toOpen, value, ' ');
            if (typeOfProperty = "Commercial")
                {
                    
                }
            else if (typeOfProperty = "Residential")
                {
                    
                }
            else
                {
                    
                }
        }
    }
    else
    {
        cout << "There was an error reading the file!";
    }
    
}
