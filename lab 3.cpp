#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Taylor Bradshaw, Section _, taylor.bradshaw0250@gmail.com
READY TO BE GRADED

Description: A program that takes the capabilities and prices of cars and determines which would be ideal for the user.

Inputs: The user will input the miles driven for year, expected gas price per gallon, and the efficiency, cost, and resale
value of each car type. They will also input their prefferred criteria, either total cost or gas consumption.

Outputs: The program will output the total cost and gas consumption for each car, as well as the car that will be best for them.

Test Case One:
Inputs:
Miles/Year: 10000, gas price: 1.50, cost of hybrid-nonhybrid: 50000-24000, MPG hybrid-nonhybrid: 30-24, resale value hybrid-nonhybrid: 45000-22000
Preference: Total Cost

Outputs:
Total Gas hybrid-nonhybrid: 1666.67-2083.33 gallons, total cost hybrid-nonhybrid: $7500.00, $5125.00
Non hybrid car better for total cost.

Test Case Two:
Inputs:
Miles/Year: 100000, gas price: 2.56, cost of hybrid-nonhybrid: 35000-15000, MPG hybrid-nonhybrid: 30-24, resale value hybrid-nonhybrid: 25000-10000
Preference: Total Cost
Outputs:
Total Gas hybrid-nonhybrid: 16666.67-20833.33 gallons, total cost hybrid-nonhybrid: $52666.67-$58333.33
Hybrid car better for total cost.

Test Case Three:
Inputs:
Miles/Year: 17000, gas price: 3.00, cost of hybrid-nonhybrid: 25000, MPG hybrid-nonhybrid: 32-25, resale value hybrid-nonhybrid: 20000-20000
Preference: Gas Consumption
Outputs:
Total Gas hybrid-nonhybrid: 2656.25-3400.00 gallons, total cost hybrid-nonhybrid: $12968.75-$13200.00
Hybrid car better for gas consumption.
*/

int main() {
    
    
    const string nonHybridString = "Non-Hybrid Car";
    const string hybridString = "Hybrid Car";
    const int YEARS = 5;
    double milesPerYear = 0;
    double gasPricePerGallon = 0;
    double efficiencyOfHybrid = 0;
    double efficiencyOfNonHybrid = 0;
    double costOfHybrid = 0;
    double costOfNonHybrid = 0;
    double resaleValueHybrid = 0;
    double resaleValueNonHybrid = 0;
    double totalGallonsHybrid = 0;
    double totalGallonsNonHybrid = 0;
    double costOfGasHybrid = 0;
    double costOfGasNonHybrid = 0;
    double depreciationHybrid = 0;
    double depreciationNonHybrid = 0;
    double totalCostHybrid = 0;
    double totalCostNonHybrid = 0;
    char userSelection = ' ';
    string optionOne = "";
    string optionTwo = "";
    
    cout << "Estimated miles driven per year: ";
    cin >> milesPerYear;
    if (milesPerYear < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Estimated miles driven per year: ";
        cin >> milesPerYear;
    }
    
    cout << "Estimated price of gas per gallon: ";
    cin >> gasPricePerGallon;
    if (gasPricePerGallon < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Estimated price of gas per gallon: ";
        cin >> gasPricePerGallon;
    }
    
    cout << "Cost of hybrid car: ";
    cin >> costOfHybrid;
    if (costOfHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Cost of hybrid car: ";
        cin >> costOfHybrid;
    }
    
    cout << "Miles per gallon of hybrid car: ";
    cin >> efficiencyOfHybrid;
    if (efficiencyOfHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Miles per gallon of hybrid car: ";
        cin >> efficiencyOfHybrid;
    }
    
    cout << "Estimated resale value of hybrid car: ";
    cin >> resaleValueHybrid;
    if (resaleValueHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Estimated resale value of hybrid car: ";
        cin >> resaleValueHybrid;
    }
    
    cout << "Cost of regular car: ";
    cin >> costOfNonHybrid;
    if (costOfNonHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Cost of regular car: ";
        cin >> costOfNonHybrid;
    }
    
    cout << "Miles per gallon of regular car: ";
    cin >> efficiencyOfNonHybrid;
    if (efficiencyOfNonHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Miles per gallon of regular car: ";
        cin >> efficiencyOfNonHybrid;
    }
    
    cout << "Estimated resale value of regular car: ";
    cin >> resaleValueNonHybrid;
    if (resaleValueNonHybrid < 1)
    {
        cout << endl << "Please input a positive, non-zero number." << endl;
        cout << "Estimated resale value of regular car: ";
        cin >> resaleValueNonHybrid;
    }
    
    //get total gallons and total cost for output
    
    totalGallonsHybrid = (milesPerYear * YEARS) / efficiencyOfHybrid;
    totalGallonsNonHybrid = (milesPerYear * YEARS) / efficiencyOfNonHybrid;
    
    costOfGasHybrid = totalGallonsHybrid * gasPricePerGallon;
    costOfGasNonHybrid = totalGallonsNonHybrid * gasPricePerGallon;
    
    depreciationHybrid = costOfHybrid - resaleValueHybrid;
    depreciationNonHybrid = costOfNonHybrid - resaleValueNonHybrid;
    
    totalCostHybrid = depreciationHybrid + costOfGasHybrid;
    totalCostNonHybrid = depreciationNonHybrid + costOfGasNonHybrid;
    
    cout << "Which is more important to you, gas consumption or total cost? (enter G for gas, T for total): ";
    cin >> userSelection;
    
    
    cout << "  --Hybrid Car Statistics--" << endl;
    cout << "Total gas consumption over 5 years: " << fixed << setprecision(2) << totalGallonsHybrid << " gallons" << endl;
    cout << "Total cost over 5 years: $" << totalCostHybrid << endl << endl;
    cout << "  --Non Hybrid Car Statistics--" << endl;
    cout << "Total gas consumption over 5 years: " << totalGallonsNonHybrid << " gallons" << endl;
    cout << "Total cost over 5 years: $" << totalCostNonHybrid << endl << endl;
    
    if (toupper(userSelection) == toupper('g'))
    {
        if (totalGallonsHybrid > totalGallonsNonHybrid)
        {
            optionOne = nonHybridString;
            optionTwo = hybridString;
        }
        else
        {
            optionOne = hybridString;
            optionTwo = nonHybridString;
        }
        cout << "The " << optionOne << " is better than the " << optionTwo << " When gas is the principle concern.";
    }
    else if (toupper(userSelection) == toupper('t'))
    {
        if (totalCostHybrid > totalCostNonHybrid)
        {
            optionOne = nonHybridString;
            optionTwo = hybridString;
        }
        else
        {
            optionOne = hybridString;
            optionTwo = nonHybridString;
        }
        cout << "The " << optionOne << " is better than the " << optionTwo << " When total cost is the principle concern.";
    }
    else
    {
        cout << "Please input G for gas, or T for total.";
        cin >> userSelection;
    }
}
