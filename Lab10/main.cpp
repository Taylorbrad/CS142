// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
using namespace std;
string getFileName()
{
    string fileName = 0;
    
    cout << "Where should I read the data from? ";
    cin >> fileName;
    
    return fileName;
}
int getLineType(string line)
{
    
}
int main()
{
    string fileName = "";
    ifstream toOpen;
    ofstream toWrite;
    stringstream ss;
    stringstream ss1;
    string address = "";
    string typeOfProperty = "";
    string line = "";
    double value = 0;
    double discount = 0;
    bool isRental = false;
    bool isDiscounted = false;
    bool isOccupied = false;
    vector<Property*> properties;
    vector<stringstream> badLinesSS;
    
    fileName = getFileName();
    
    toOpen.open((fileName + ".txt"));
    
    if (toOpen.is_open());
    {
        for (int id = 0; !toOpen.eof(); ++id)
        {
            
            getline(toOpen, line, '\n') //put the entire line in 'line' string
                /*TODO: try pulling from ss instead of toOpen in the following lines */
            /*
            getline(toOpen, typeOfProperty, ' ');
            getline(toOpen, isRental, ' ');
            getline(toOpen, value, ' ');
            if (typeOfProperty = "Commercial")
            {
                
                getline(toOpen, isDiscounted, ' ');
                getline(toOpen, discount, ' ');
                
                getline(toOpen, address, '\n');
                    
                Commercial* test = new Commercial(address, isDiscounted,  isRental, discount, value, id);
                properties.push_back(test); 
            }
            else if (typeOfProperty = "Residential")
            {
                getline(toOpen, isOccupied, ' ');
                getline(toOpen, address, '\n');
                
                Residential* test1 = new Residential(address, isOccupied, isRental, value, id);
                properties.push_back(test1);
            }
        
            else
            {
                badLinesSS.push_back(ss);
            }
            */
        }
    }
    else
    {
        cout << "There was an error reading the file!";
    }
    //TODO: Open new file for writing to, and write the necessary output.
    toWrite.open((fileName + "OUT.txt"));
    
    if (toWrite.is_open())
    {
        
    }
    else
    {
        cout << "There was an error reading the file!";
    }
}
