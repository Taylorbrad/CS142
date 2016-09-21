/*
Taylor Bradshaw, Section 005, taylor.bradshaw0250@gmail.com

Description: 

Inputs: 

Outputs: 

Test Case One:
Inputs:
Outputs:

Test Case Two:
Inputs:
Outputs:

Test Case Three:
Inputs:
Outputs:
*/
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    string plinkoRow = "|.........|";
    int slotSelection = 0;
    int randomZeroOrOne = 0;
    
    //Set random number generation seed
    srand(time(NULL));
    
for (int selection = 1; selection != 0;)
{
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
            cout << endl;
            for (int i = 0; i < 10; ++i)
            {
                plinkoRow.replace(slotSelection + 1, 1, "O");
                cout << plinkoRow << endl;
                //cout << slotSelection << endl;
                plinkoRow = "|.........|";
                //Determine whether chip moves left or right
                randomZeroOrOne = rand() % 2;
                
                if ((randomZeroOrOne == 0 && slotSelection != 0) || slotSelection == 8)
                {
                    --slotSelection;
                }
                else if (randomZeroOrOne == 1 || slotSelection == 0)
                {
                    ++slotSelection;
                }
                //plinkoRow.replace(slotSelection - 2, 1, "O");
                
                //cout << endl << "Current Slot: " << slotSelection;
            }
            
        break;
        case 2:
        
        break;
        default:
        cout << endl << "---Invalid Selection. Please select a number from the menu.---" << endl << endl;
        break;
    }
    
}
return 0;
}
