#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

Residential::Residential(string address, bool isOccupied, bool isRental, double value, int id) : Property(address, isRental, value, id)
{
  this->isOccupied = isOccupied;
}
