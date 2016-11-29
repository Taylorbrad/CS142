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
    
    public:
    string toString();
    string getAddress();
}
