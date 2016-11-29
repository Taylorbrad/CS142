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
    this->address = addressInput;
}

string Property::toString()
{
    //stringstream ss;
    //ss << "Address: " << this->address;
    cout << this->address;
}
string Property::getAddress()
{
    return this->address;
}
