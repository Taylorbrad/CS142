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
int main()
{
    string fileName = "";
    ifstream toOpen;
    ofstream toWrite;
    stringstream ss;
    stringstream ss1;
    string address = "";
    string typeOfProperty = "";
    double value = 0;
    double discount = 0;
    bool isRental = false;
    bool isDiscounted = false;
    bool isOccupied = false;
    vector<Commercial*> commercialProperties;
    vector<Residential*> residentialProperties;
    vector<stringstream> badLinesSS;
    
    fileName = getFileName();
    
    toOpen.open((fileName + ".txt"));
    
    if (toOpen.is_open());
    {
        for (int id = 0; !toOpen.eof(); ++id)
        {
            getline(toOpen, ss, '\n') //put the entire line in ss
                /*TODO: try pulling from ss instead of toOpen in the following lines */
            getline(toOpen, typeOfProperty, ' ');
            getline(toOpen, isRental, ' ');
            getline(toOpen, value, ' ');
            if (typeOfProperty = "Commercial")
            {
                
                getline(toOpen, isDiscounted, ' ');
                getline(toOpen, discount, ' ');
                getline(toOpen, address, '\n');
                    
                Commercial* test = new Commercial(address, isDiscounted,  isRental, discount, value, id);
                commercialProperties.push_back(test); 
            }
            else if (typeOfProperty = "Residential")
            {
                getline(toOpen, isOccupied, ' ');
                getline(toOpen, address, '\n');
                
                Residential* test1 = new Residential(address, isOccupied, isRental, value, id);
                residentialProperties.push_back(test1);
            }
            else
            {
                badLinesSS.push_back(ss);
            }
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
