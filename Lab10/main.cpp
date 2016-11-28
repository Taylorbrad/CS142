// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

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
    
    fileName = getFileName();
    
    toOpen.open("fileName");
    
    if (toOpen.is_open();
    {
        
    }
    else
    {
        cout << "There was an error reading the file!";
    }
    
}
