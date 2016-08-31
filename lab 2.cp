#include <iostream>
using namespace std;

int main()
{
  int numOfGuests = 0;
  int numOfGuestsTemp = 0;
  double tipPercentage = 0;
  int largePizzas = 0;
  int mediumPizzas = 0;
  int smallPizzas = 0;
  
  cout << "How many guests will be at the party?";
  cin >> numOfGuests;
  //cout << ""
  
  numOfGuestsTemp = numOfGuests;
  largePizzas = numOfGuestsTemp / 7;
  numOfGuestsTemp -= (largePizzas * 7);
  mediumPizzas = numOfGuestsTemp / 3;
  numOfGuestsTemp -= (mediumPizzas * 3);
  smallPizzas = numOfGuestsTemp;
  
}
