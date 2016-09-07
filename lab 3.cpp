#include <iostream>
#include <string>
using namespace std;

int main() {
    
    double milesPerYear = 0;
    double gasPricePerGallon = 0;
    double efficiencyOfHybrid = 0;
    double efficiencyOfNonHybrid = 0;
    double costOfHybrid = 0;
    double costOfNonHybrid = 0;
    double resaleValueHybrid = 0;
    double resaleValueNonHybrid = 0;
    
    cout << "Estimated miles driven per year: ";
    cin >> milesPerYear;
    
    cout << "Estimated price of gas per gallon: ";
    cin >> gasPricePerGallon;
    
    cout << "Cost of hybrid car: ";
    cin >> costOfHybrid;
    
    cout << "Miles per gallon of hybrid car: ";
    cin >> efficiencyOfHybrid;
    
    cout << "Estimated resale value of hybrid car: ";
    cin >> resaleValueHybrid;
    
    cout << "Cost of regular car: ";
    cin >> costOfNonHybrid;
    
    cout << "Miles per gallon of regular car: ";
    cin >> efficiencyOfNonHybrid;
    
    cout << "Estimated resale value of regular car: ";
    cin >> resaleValueNonHybrid;
}
