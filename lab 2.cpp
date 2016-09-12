#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
Taylor Bradshaw, Section _, taylor.bradshaw0250@gmail.com
READY TO BE GRADED

Purpose: This is a program which calculates the total bill for a group of people going to a pizza place.

Inputs: The amount of people eating and the tip percentage.

Outputs: The area that each person can eat, how many of each type of pizza, and the total bill.

Test Case One:
Test Case Two:
Test Case Three:
*/

int main()
{
	const double SMALL_DIAMETER = 12;
	const double MEDIUM_DIAMETER = 16;
	const double LARGE_DIAMETER = 20;
	const double SMALL_PRICE = 7.28;
	const double MEDIUM_PRICE = 11.48;
	const double LARGE_PRICE = 14.68;
	const double PI = 3.14159;
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
	largePizzas = numOfGuestsTemp / 7;
	numOfGuestsTemp -= (largePizzas * 7);
	mediumPizzas = numOfGuestsTemp / 3;
	numOfGuestsTemp -= (mediumPizzas * 3);
	smallPizzas = numOfGuestsTemp;

	cout << "\nLarge: " << largePizzas << "\nMedium: " << mediumPizzas << "\nSmall: " << smallPizzas;

	smallArea = smallPizzas * (PI * pow((SMALL_DIAMETER / 2), 2));
	mediumArea = mediumPizzas * (PI * pow((MEDIUM_DIAMETER / 2), 2));
	largeArea = largePizzas * (PI * pow((LARGE_DIAMETER / 2), 2));

	totalArea = smallArea + mediumArea + largeArea;
	areaPerPerson = totalArea / numOfGuests;

	cout << "\n\nThe total area of pizza is: " << totalArea << " sq. inches\nEach person can eat: " << areaPerPerson << " sq. inches\n";

	cout << "\nTip percentage: ";
	cin >> tipPercentage;

	smallTotal = smallPizzas * SMALL_PRICE;
	mediumTotal = mediumPizzas * MEDIUM_PRICE;
	largeTotal = largePizzas * LARGE_PRICE;
	totalBill = smallTotal + mediumTotal + largeTotal;
	totalBill = (totalBill * (tipPercentage / 100)) + totalBill;

	//cout << "ST: " << smallTotal << "MT: " << mediumTotal << "LT: " << largeTotal;
	cout << "\nThe total bill is: " << fixed << setprecision(0) << totalBill << "\n\n";

	system("pause");
}
