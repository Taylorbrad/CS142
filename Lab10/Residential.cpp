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
string Residential::toString()
{
  stringstream ss;
  string isRentalString = " NOT Rental ";
  string isOccupiedString = " NOT Occupied ";
  if (this->isOccupied)
  {
    isOccupiedString = " Occupied ";
  }
  if (this->isRental)
  {
    isRentalString = " Rental ";
  }
  ss << "Property id: " << this->id << " Address: " << this->address << " " << isRentalString <<  " Estimated Value: " << this->value << isOccupiedString;
  return ss.str();
}
