#include <iostream>
#include <cmath>
using namespace std;

int main()
{
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
  const double smallDiameter = 12;
  const double mediumDiameter = 16;
  const double largeDiameter = 20;
  const double smallPrice = 7.28;
  const double mediumPrice = 11.48;
  const double largePrice = 14.68;
  const double PI = 3.14159;
  
  cout << "Amount of guests attending: ";
  cin >> numOfGuests;
  
  numOfGuestsTemp = numOfGuests;
  largePizzas = numOfGuestsTemp / 7;
  numOfGuestsTemp -= (largePizzas * 7);
  mediumPizzas = numOfGuestsTemp / 3;
  numOfGuestsTemp -= (mediumPizzas * 3);
  smallPizzas = numOfGuestsTemp;
  
  cout << "\nLarge:" << largePizzas << "\nMedium:" << mediumPizzas << "\nSmall: " << smallPizzas;
  
  smallArea = smallPizzas * ( PI * pow((smallDiameter / 2), 2));
  mediumArea = mediumPizzas * ( PI * pow((mediumDiameter / 2), 2));
  largeArea = largePizzas * ( PI * pow((largeDiameter / 2), 2));
  totalArea = smallArea + mediumArea + largeArea;
  areaPerPerson = totalArea / numOfGuests;
  cout << "\nThe total area of pizza is: " << totalArea << " sq. inches\nEach person can eat: " << areaPerPerson << " sq. inches\n";
  
  cout << "Tip percentage: ";
  cin >> tipPercentage;
  
  smallTotal = smallPizzas * smallPrice;
  mediumTotal = mediumPizzas * mediumPrice;
  largeTotal = largePizzas * largePizzas;
  totalBill = smallTotal + mediumTotal + largeTotal;
  totalBill = (totalBill * tipPercentage) + totalBill;
  
  cout << "The total bill is: " << totalBill;
}
