// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

Property::Property(string addressInput)
{
    address = addressInput;
}

string Property::toString()
{
    stringstream ss;
    ss << "Address: " << this->address;
    return ss.str();
}
string Property::getAddress()
{
    return this->address;
}
