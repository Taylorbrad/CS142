/* Mark Taylor Bradshaw, Section 5, CS 142 Fall 2016 Midterm 1 */

#include <iostream>
#include <string>
using namespace std;

bool determineIfLeapYear(int);
bool determineIfValidDaysInMonth(string*, int*, int, int, bool);
bool determineIfValidInput(string, int, int, int, bool);
int getMonthNumber(/* ADD DESCRIPTIONS TO VARS */int, string, string*);
int getWeekDay();

int main()
{
    int yearNum = 0;
    int dayNum = 0;
    int monthNum = 0;
    int monthDaysArray[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekDayNumArray[] = {1, 2, 3, 4, 5, 6, 7};
    string month = "";
    string garbageComma = "";
    string monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string daysOfWeekArray[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    bool isLeapYear = false;
    bool isValidDays = false;
    bool isInputValid = false;
    
    while (!isInputValid)
    {
        cout << "Enter the date you would like to learn all about or whatever (ex: January 1, 2000): ";
        cin >> month >> dayNum >> garbageComma >> yearNum;
        
        monthNum = getMonthNumber(monthNum, month, monthArray);
        isLeapYear = determineIfLeapYear(yearNum);
        isValidDays = determineIfValidDaysInMonth(monthArray, monthDaysArray, monthNum, dayNum, isLeapYear);
        isInputValid = determineIfValidInput(month, dayNum, yearNum, monthNum, isValidDays);
        
        if (dayNum == 0 || yearNum == 0)
        {
            return 0;
        }
    }
    
    return 0;
}
bool determineIfLeapYear(int yearNum)
{
    //Returns true if it is leap year, false if not
    double yearNumDouble;
    bool isLeapYear = false;
    yearNumDouble = yearNum;
    
    if (((yearNumDouble / 100) - (yearNum /100)) == 0 && ((yearNumDouble / 400) - (yearNum / 400)) == 0 && ((yearNumDouble / 4) - (yearNum / 4)) == 0)
    {
        isLeapYear = true;
    }
    else if ((yearNumDouble / 4) - (yearNum / 4) == 0 && !((yearNumDouble / 100) - (yearNum /100) == 0))
    {
        isLeapYear = true;
    }
    return isLeapYear;
}
bool determineIfValidDaysInMonth(string* monthArray, int* monthDaysArray, int monthNum, int dayNum, bool isLeapYear)
{
    //Returns true if the month and days line up, false if not.
    bool isValidDays = false;
    /*
    for (int i = 0; i < 12; ++i)
    {
        if (
    }
    */
    if (monthNum != 2 || !isLeapYear)
    {
        /* cout << "not february or not leap year"; */
        isValidDays = ((dayNum <= monthDaysArray[monthNum - 1]) && dayNum > 0);
    }
    else
    {
        if (isLeapYear && monthNum == 2)
        {
            /* cout << "leap year and february"; */
            isValidDays = ((dayNum <= monthDaysArray[monthNum - 1] + 1) && dayNum > 0);
        }
    }
    /*
    if (isValidDays)
    cout << "days are valid";
    else
    cout << "days are invalid";
    return isValidDays;
    */
    
}
bool determineIfValidInput(string month, int dayNum, int yearNum, int monthNum, bool isValidDays)
{
    //Returns true if input is valid according to parameters outlined
    const int YEAR_MIN = 1582;
    bool isInputValid = false;
    /* cout << month << "/" << dayNum << "/" << yearNum; */
    
    //Determine validity of input
    if ((yearNum <= YEAR_MIN) || !isValidDays || (monthNum  == 0/*REPLACE MAGIC #*/))
    {
        //cout << "false";
        isInputValid = false;
    }
    else
    {
        //cout << "true";
        isInputValid = true;
    }
    
    
    if (!isInputValid)
    {
        cout << endl << "Invalid input!" << endl << endl;
    }
    return isInputValid;
}
int getMonthNumber(int monthNum, string month, string* monthArray)
{
    //Returns integer value of the month, 1 for January, 2 for February, etc. Returns 0 if month input is invalid/unrecognized.
    int i = 0;
    for (i = 0; i < 12; ++i)
    {
        if (month.compare(monthArray[i]) == 0)
        {
            monthNum = i + 1;
            i += 12;
        }
    }
    /* cout << monthNum; */
    
    return monthNum;
}
int getDayOfWeek()
{
    
}
