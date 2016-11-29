#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Property
{
    private:
    string address;
    bool isRental;
    double value = 0;
    int id = 0;
    
    public:
    Property(string);
    string toString();
    string getAddress();
}
