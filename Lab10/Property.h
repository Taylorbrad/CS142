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
    
    public:
    Property(string);
    string toString();
    string getAddress();
}
