#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

class Commercial : public Property
{
    public:
    Commercial(string address, bool isDiscounted, bool isRental, double discount, double value, int id);
    
    private:
    bool isDiscounted;
    double discount = 0;
};
