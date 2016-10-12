#include <iostream>
#include <string>
using namespace std;

bool isValidInput(bool, string, int, int);
int main()
{
    int yearNum = 0;
    int dayNum = 0;
    int monthNum = 0;
    string month = "";
    string garbageComma = "";
    bool inputIsValid = false;
    
    while (!inputIsValid)
    {
        cout << "Enter the date you would like to learn all about or whatever (ex: January 1, 2000): ";
        cin >> month >> dayNum >> garbageComma >> yearNum;
        
        inputIsValid = isValidInput(inputIsValid, month, dayNum, yearNum);
    }
    
    return 0;
}
bool isValidInput(bool inputIsValid, string month, int dayNum, int yearNum)
{
    //cout << month << "/" << dayNum << "/" << yearNum;
    
    //Determine validity of input
    if ((yearNum <= 1582) || (dayNum <= 0 || dayNum >= 32) || (1 == 2))
    {
        //cout << "false";
        inputIsValid = false;
    }
    else
    {
        //cout << "true";
        inputIsValid = true;
    }
    
    
    if (!inputIsValid)
    {
        cout << endl << endl << "Invalid input!" << endl << endl;
    }
    return inputIsValid;
}
