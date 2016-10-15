/* Mark Taylor Bradshaw, Section 5, CS 142 Fall 2016 Midterm 1 */

#include <iostream>
#include <string>
using namespace std;

bool DetermineIfLeapYear(int);
bool DetermineIfValidDaysInMonth(int, int, bool);
bool DetermineIfValidInput(string, int, int, int, bool);
int GetMonthNumber(/* ADD DESCRIPTIONS TO VARS */int, string);
int GetWeekDayNumber(int totalDays);
int GetWeekDay(int);
int GetTotalDaysUntilInput(int, int, int);

const string MONTH_ARRAY[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const string WEEK_DAYS_ARRAY[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int MONTH_DAYS_ARRAY[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	int yearNum = 0;
	int dayNum = 0;
	int monthNum = 1;
	int daysBetweenDates = 0;
	
	//int daysOfWeekArray[] = { 1, 2, 3, 4, 5, 6, 7 };
	string month = "";
	string garbageComma = "";
	
	bool isLeapYear = false;
	bool isValidDays = false;
	bool isInputValid = false;
	
	while (monthNum != 0)
	{
	    monthNum = 0;
	    yearNum = 0;
	    dayNum = 0;
		cout << "Enter the date (ex: January 1, 2000) or enter '0 0 0 0' to exit: ";
		cin >> month >> dayNum >> garbageComma >> yearNum;
		
		if (dayNum == 0 || yearNum == 0)
		{
		    cout << endl << "---Exiting---" << endl;
		    system("pause");
		    return 0;
		}
		
		monthNum = GetMonthNumber(monthNum, month);
		isLeapYear = DetermineIfLeapYear(yearNum);
		isValidDays = DetermineIfValidDaysInMonth(monthNum, dayNum, isLeapYear);
		isInputValid = DetermineIfValidInput(month, dayNum, yearNum, monthNum, isValidDays);
		daysBetweenDates = GetTotalDaysUntilInput(yearNum, monthNum, dayNum);
		
		if (isInputValid)
		{
		    cout << endl << month << " ";
		    cout << dayNum << ", " << yearNum << " is a ";
		    cout << WEEK_DAYS_ARRAY[GetWeekDayNumber(daysBetweenDates)] << endl << endl;
		}
	}
	system("pause");
	return 0;
}
bool DetermineIfLeapYear(int yearNum)
{
	//Returns true if it is leap year, false if not
	double yearNumDouble;
	bool isLeapYear = false;
	yearNumDouble = yearNum;

	if (((yearNumDouble / 100) - (yearNum / 100)) == 0 && ((yearNumDouble / 400) - (yearNum / 400)) == 0 && ((yearNumDouble / 4) - (yearNum / 4)) == 0)
	{
		isLeapYear = true;
	}
	else if ((yearNumDouble / 4) - (yearNum / 4) == 0 && !((yearNumDouble / 100) - (yearNum / 100) == 0))
	{
		isLeapYear = true;
	}
	return isLeapYear;
}
bool DetermineIfValidDaysInMonth(int monthNum, int dayNum, bool isLeapYear)
{
	//Returns true if the month and days line up, false if not.
	bool isValidDays = false;

	if (monthNum != 2 || !isLeapYear)
	{
		isValidDays = ((dayNum <= MONTH_DAYS_ARRAY[monthNum - 1]) && dayNum > 0);
	}
	else
	{
		if (isLeapYear && monthNum == 2)
		{
			isValidDays = ((dayNum <= MONTH_DAYS_ARRAY[monthNum - 1] + 1) && dayNum > 0);
		}
	}
	
	return isValidDays;
}
bool DetermineIfValidInput(string month, int dayNum, int yearNum, int monthNum, bool isValidDays)
{
	//Returns true if input is valid according to parameters outlined
	const int YEAR_MIN = 1582;
	bool isInputValid = false;

	//Determine validity of input
	if ((yearNum <= YEAR_MIN) || !isValidDays || (monthNum == 0/*REPLACE MAGIC #*/))
	{
		isInputValid = false;
	}
	else
	{
		isInputValid = true;
	}

	if (!isInputValid)
	{
		cout << endl << "Invalid input!" << endl << endl;
	}
	
	return isInputValid;
}
int GetMonthNumber(int monthNum, string month)
{
	//Returns integer value of the month, 1 for January, 2 for February, etc. Returns 0 if month input is invalid/unrecognized.
	int i = 0;
	
	for (i = 0; i < 12; ++i)
	{
		if (month.compare(MONTH_ARRAY[i]) == 0)
		{
			monthNum = i + 1;
			i += 12;
		}
	}
	/* cout << monthNum; */

	return monthNum;
}
int GetTotalDaysUntilInput(int yearNum, int monthNum, int dayNum)
{
    const int DAYS_IN_YEAR = 365;
    const int DAYS_IN_LEAP_YEAR = 366;
    const int YEAR_MIN = 1583;
	int dayNumTemp = 0;
	int monthNumTemp = 0;
	int yearNumTemp = 0;
	int totalDays = 0;

	dayNumTemp = dayNum;
	monthNumTemp = monthNum;
	yearNumTemp = yearNum;
	
	for (; yearNumTemp > YEAR_MIN; --yearNumTemp)
	{
		if (DetermineIfLeapYear(yearNumTemp))
		{
			totalDays += DAYS_IN_LEAP_YEAR;
		}
		else
		{
			totalDays += DAYS_IN_YEAR;
		}

	}
	if (monthNumTemp == 1 && DetermineIfLeapYear(yearNum))
	{
	    totalDays -= 1;
	}
	for (; monthNumTemp > 1; --monthNumTemp)
	{
		totalDays += MONTH_DAYS_ARRAY[monthNumTemp - 2];
		
		if (monthNumTemp == 2)
		{
		    totalDays += 1;
		}
		else if (monthNumTemp == 3)
		{
		    totalDays -= 1;
		}
	}
	for (; dayNumTemp > 1; --dayNumTemp)
	{
	    
		totalDays += 1;
	}
	return totalDays;
}
int GetWeekDayNumber(int totalDays)
{
    //Calculates what day of the week it is based on total days elapsed since January 1, 1853
    //This is accomplished by dividing total number of days by seven, then subtracting everything left of the decimal place.
    //The remaining decimal is then multiplied by 100 so that it can be an int type, so it works with the switch statement intended.
    
    const int DAYS_IN_WEEK = 7;
	const int MULTIPLY_BY_100 = 100;
	int weekDay = 0;
	int totalDaysInt = 0;
	double totalDaysDouble = totalDays;
	double weekDayDouble = 0;
	
	totalDaysInt = totalDays;
	weekDayDouble = totalDaysDouble / DAYS_IN_WEEK;
	weekDayDouble -= totalDaysInt / DAYS_IN_WEEK;
	weekDayDouble *= MULTIPLY_BY_100;
	weekDay = weekDayDouble;
	
	return GetWeekDay(weekDay);
}
int GetWeekDay(int weekDay)
{
	//Returns subscript for the weekDaysArray constant corresponding to the appropriate week day
	
	switch (weekDay)
	{
	case 0:
	case 10:
		weekDay = 5;
		break;

	case 14:
		weekDay = 6;
		break;

	case 28:
		weekDay = 0;
		break;

	case 42:
		weekDay = 1;
		break;

	case 57:
		weekDay = 2;
		break;

	case 71:
		weekDay = 3;
		break;

	case 85:
		weekDay = 4;
		break;
	}

	return weekDay;
}
