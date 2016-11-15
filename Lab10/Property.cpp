// Example program
#include <iostream>
#include <string>
#include <sstream>
#include "Property.h"
using namespace std;

Property::Property(string addressInput)
{
    address = addressInput;
}

Property::toString()
{
    stringstream ss;
    ss << "Address: " << address;
    return ss.str();
}
