#include <iostream>
#include <string>
using namespace std;

int main()
{
    int yearNum = 0;
    int dayNum = 0;
    int monthNum = 0;
    string month = "";
    string day = "";
    string year = "";
    string input = "";
    bool inputIsValid = false;
    
    while (!inputIsValid)
    {
        cout << "Enter the date you would like to learn all about or whatever (MM/DD/YYYY): ";
        cin >> input;
        
        //Separate string into sections
        
        /* FIND OUT HOW TO CONVERT STRING TO INT IN TEXTBOOK */
        month = input.substr(0,2);
        day = input.substr(3,2);
        year = input.substr(6,4);
        
        /* cout << month << "/" << day << "/" << year; */
        
        //Determine validity of input
        if ((yearNum <= 1582) || () || ())
        {
            
        }
        
        
        if (!inputIsValid)
        {
            cout << endl << endl << "Invalid input!" << endl << endl;
        }
    }
    
    return 0;
}
