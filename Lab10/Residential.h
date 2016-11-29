#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;

class Residential : public Property
{
    public:
    Residential(string address, bool isOccupied, bool isRental, double value, int id) : Property(address, isRental, value, id);
    string toString();
    
    private:
    bool isOccupied;
};
