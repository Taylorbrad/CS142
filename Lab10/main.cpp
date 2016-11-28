
#include <iostream>
#include <string>
using namespace std;


string getFileName()
{
    string fileName = 0;
    
    cout << "Input file name (with the extension): ";
    cin >> fileName;
    
    return fileName;
}
int main()
{
    string fileName = "";
    
    fileName = getFileName();
}
