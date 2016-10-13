#include <iostream>
#include <string>
using namespace std;

bool isValidInput(bool, string, int, int);
int monthNumber(int);

int main()
{
    const YEAR_MIN = 1582;
    const DAY_MIN = 1;
    const DAY_MAX = 31;
    int yearNum = 0;
    int dayNum = 0;
    int monthNum = 0;
    string month = "";
    string garbageComma = "";
    string monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    bool inputIsValid = false;
    bool isMonth = false;
    
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
    if ((yearNum <= 1582) || !(dayNum >= 1 || dayNum <= 31) || (1 == 2))
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
int monthNumber(int monthNum)
{
    for (int i = 0; i < 12; ++i)
    {
        
    }
    cout << i;
    return monthNum;
}
