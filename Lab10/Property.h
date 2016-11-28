#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Property
{
    private:
    string address;
    
    public:
    string toString();
    string getAddress();
}
