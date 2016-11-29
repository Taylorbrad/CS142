#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

Commercial::Commercial(string address, bool isDiscounted, bool isRental, double discount, double value) : Property(address, isRental)
{
  this->isDiscounted = isDiscounted;
  this->discount = discount;
  this->value = value;
}
Commercial::toString()
{
  
}
