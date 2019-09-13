#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Taylor Bradshaw, Section _, taylor.bradshaw0250@gmail.com
READY TO BE GRADED   wheves
Purpose: This is a program which calculates the total bill for a group of people going to a pizza place.
Inputs: The amount of people eating and the tip percentage.
Outputs: The area that each person can eat, how many of each type of pizza, and the total bill.
Test Case One:
Test Case Two:
Test Case Three:
*/

int main()
{
	const double SMALL_RADIUS = 6;
	const double MEDIUM_RADIUS = 8;
	const double LARGE_RADIUS = 10;
	const double SMALL_PRICE = 7.28;
	const double MEDIUM_PRICE = 11.48;
	const double LARGE_PRICE = 14.68;
	const double PI = 3.14159;
	const int SQUARE = 2;
	const int CONVERT_TO_PERCENTAGE = 100;
	const int PEOPLE_PER_LARGE = 7;
	const int PEOPLE_PER_MEDIUM = 3;
	const int TO_NEAREST_DOLLAR = 0;
	int numOfGuests = 0;
	int numOfGuestsTemp = 0;
	int largePizzas = 0;
	int mediumPizzas = 0;
	int smallPizzas = 0;
	double totalArea = 0;
	double largeArea = 0;
	double mediumArea = 0;
	double smallArea = 0;
	double areaPerPerson = 0;
	int tipPercentage = 0;
	double totalBill = 0;
	double smallTotal = 0;
	double mediumTotal = 0;
	double largeTotal = 0;


	cout << "Amount of guests attending: ";
	cin >> numOfGuests;

	numOfGuestsTemp = numOfGuests;
	largePizzas = numOfGuestsTemp / PEOPLE_PER_LARGE;
	numOfGuestsTemp -= (largePizzas * PEOPLE_PER_LARGE);
	mediumPizzas = numOfGuestsTemp / PEOPLE_PER_MEDIUM;
	numOfGuestsTemp -= (mediumPizzas * PEOPLE_PER_MEDIUM);
	smallPizzas = numOfGuestsTemp;

	cout << "\nLarge: " << largePizzas << "\nMedium: " << mediumPizzas << "\nSmall: " << smallPizzas;
    
    
    
	smallArea = smallPizzas * (PI * pow((SMALL_RADIUS), SQUARE));
	mediumArea = mediumPizzas * (PI * pow((MEDIUM_RADIUS), SQUARE));
	largeArea = largePizzas * (PI * pow((LARGE_RADIUS), SQUARE));

	totalArea = smallArea + mediumArea + largeArea;
	areaPerPerson = totalArea / numOfGuests;

	cout << "\n\nThe total area of pizza is: " << totalArea << " sq. inches\nEach person can eat: " << areaPerPerson << " sq. inches\n";

	cout << "\nTip percentage: ";
	cin >> tipPercentage;

	smallTotal = smallPizzas * SMALL_PRICE;
	mediumTotal = mediumPizzas * MEDIUM_PRICE;
	largeTotal = largePizzas * LARGE_PRICE;
	totalBill = smallTotal + mediumTotal + largeTotal;
	totalBill = (totalBill * (tipPercentage / CONVERT_TO_PERCENTAGE)) + totalBill;

	//cout << "ST: " << smallTotal << "MT: " << mediumTotal << "LT: " << largeTotal;
	cout << "\nThe total bill is: $" << fixed << setprecision(TO_NEAREST_DOLLAR) << totalBill << "\n\n";

	system("pause");
}
