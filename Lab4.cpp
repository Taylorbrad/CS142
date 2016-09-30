/*
Taylor Bradshaw, Section 005, taylor.bradshaw0250@gmail.com
Description: This program simulates a plinko board with single and multiple chip drops, outputting the amount you won.
Inputs: Menu selection, amount of chips to drop, which slot to drop into.
Outputs: how much money you won, the path of the chip, if you have input an invalid selection.

Test Case One:
Inputs: -1, 1, -1, 1, 1
Outputs: Invalid selection, Invalid selection, [1.0 1.5 2.0 2.5 3.0 3.5 4.0 3.5 3.0 3.5 3.0 2.5 2.0], Your winnings are: $1000.00
Congratulations!

Test Case Two:
Inputs:
Outputs:

Test Case Three:
Inputs:
Outputs:
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;
//REMOVE MAGIC NUMBERS
int main()
{
    double slotSelection = 0;
    double slotSelectionLocal = 0;
    double winningsAverage = 0;
    double amountOfChips = 0;
    double amountOfChipsTotal = 0;
    double winningsTotal = 0;
    int finalSlot = 0;
    int randomZeroOrOne = 0;
    
    //Set random number generation seed
    srand(time(0));
    
for (int selection = 1; selection != 0;)
{
    winningsTotal = 0;
    
    cout << endl << "Select an option:" << endl;
    cout << "0: Quit" << endl;
    cout << "1: Drop a single Plinko chip into one slot" << endl;
    cout << "2: Drop multiple Plinko chips into one slot" << endl;
    cout << "Selection: ";
    cin >> selection;
    
    switch (selection)
    {
        case 0:
            cout << endl << "...Exiting..." << endl;
        
        break;
        case 1:
            cout << "Which slot would you like to drop the chip into? (0-8): ";
            cin >> slotSelection;
            
            if (slotSelection < 0 || slotSelection > 8)
            {
                cout << endl << "---Invalid Selection. Please select a slot between 0 and 8---" << endl << endl;
            }
            else
            {
            cout << endl << endl;
            cout << "[";
            for (int i = 0; i < 13; ++i)
            {
                cout << fixed << setprecision(1) << slotSelection << " ";
                
                //Determine whether chip moves left or right
                randomZeroOrOne = rand() % 2;
                
                if ((randomZeroOrOne == 0 && slotSelection != 0) || slotSelection == 8)
                {
                    slotSelection -= .5;
                }
                else if (randomZeroOrOne == 1 || slotSelection == 0)
                {
                    slotSelection += .5;
                }
            }
            cout << slotSelection;
            
            finalSlot = slotSelection;
            
            switch(finalSlot)
            {
            
                case 0:
                case 8:
                    winningsTotal = 100;
                break;
                
                case 1:
                case 7:
                    winningsTotal = 500;
                break;
                
                case 2:
                case 6:
                    winningsTotal = 1000;
                break;
                
                case 3:
                case 5:
                    winningsTotal = 0;
                break;
                
                case 4:
                    winningsTotal = 10000;
                break;
            }
            
            cout << "]" << endl << endl;
            cout << "Your winnings are: $" << fixed << setprecision(2) << winningsTotal << endl;
            cout << "Congratulations!" << endl << endl;
            }
        break;
        case 2:
        cout << "How many chips would you like to drop?" << endl;
        cin >> amountOfChips;
        if (amountOfChips < 0)
        {
            cout << endl << "---Invalid Selection. Please select a number larger than 0---" << endl << endl;
        }
        else
        {
            amountOfChipsTotal = amountOfChips;
            cout << "Which slot would you like to drop the chips into? (0-8): ";
            cin >> slotSelection;
            cout << endl << endl;
            if (slotSelection < 0 || slotSelection > 8)
            {
                cout << endl << "---Invalid Selection. Please select a slot between 0 and 8---" << endl << endl;
            }
            else
            {
                for (int chipsLocal = amountOfChips; chipsLocal > 0; --chipsLocal)
                {
                    slotSelectionLocal = slotSelection;
                    
                    for (int i = 1; i < 13; ++i)
                    {
                        //Determine whether chip moves left or right
                        randomZeroOrOne = rand() % 2;
                        
                        if ((randomZeroOrOne == 0 && slotSelectionLocal != 0) || slotSelectionLocal == 8)
                        {
                            slotSelectionLocal -= .5;
                        }
                        else if (randomZeroOrOne == 1 || slotSelectionLocal == 0)
                        {
                            slotSelectionLocal += .5;
                        }
                    }
                    finalSlot = slotSelectionLocal;
                    
                    switch(finalSlot)
                    {
                    
                        case 0:
                        case 8:
                        winningsTotal += 100;
                        break;
                        
                        case 1:
                        case 7:
                        winningsTotal+= 500;
                        break;
                        
                        case 2:
                        case 6:
                        winningsTotal += 1000;
                        break;
                        
                        case 3:
                        case 5:
                        winningsTotal += 0;
                        break;
                        
                        case 4:
                        winningsTotal += 10000;
                        break;
                    }
                }
                winningsAverage = winningsTotal / amountOfChipsTotal;
                
                cout << "The total winnings for " << amountOfChips << " chips are: $" << fixed << setprecision(2) << winningsTotal << endl;
                cout << "The average winnings per chip drop is: $" << winningsAverage << endl;
            }
        }
        break;
        default:
        cout << endl << "---Invalid Selection. Please select a number from the menu---" << endl << endl;
        break;
    }
    
}
return 0;
}
