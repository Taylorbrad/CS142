// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

Property::Property(string addressInput, bool isRental, double value, int id)
{
    this->isRental = isRental;
    this->value = value;
    this->id = id;
    this->address = addressInput;
}
/*
string Property::toString()
{
    //stringstream ss;
    //ss << "Address: " << this->address;
    return this->address;
}
*/
