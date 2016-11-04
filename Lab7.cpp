#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

int menuSelection(int selection, vector<string>& restaurants);
void displayRestaurants(const vector<string> restaurants);
void addRestaurant(vector<string>& restaurants);
string removeRestaurant(vector<string>& restaurants, string toFind);
void shuffleVector(vector<string>& restaurants);
string tournament(vector<string>& restaurants);
void incorrectInput();
int checkIfIsPower(int numToCheck);
int findRestaurant(vector<string>& restaurants, string toFind);

const int ARBITRARY_ITERATION_NUMBER = 100;
const int FALSE_RETURN_VALUE = -1;

/*
Taylor Bradshaw, Section _, taylor.bradshaw0250@gmail.com
Description: Restaurant tournament simulator
Inputs: Menu selections, restaurant names to add or remove.
Outputs: list of restaurants, winner of tournament, various clarification/updating text.

Test Case One
Inputs: Menu option 1, -1, 7, Menu option 4, Menu option 1, Menu option 6.
Outputs:
Restaurant list: McDonalds, Little Caesar's, Arby's, Pizza Hut, Sonic, Winger's, Panda Express, In-N-Out Burger.
Invalid selection, invalid selection.
Ensure list has been shuffled.

Test Case Two
Inputs: Menu option 3, "Arby's", Menu option 5, Menu option 2, "Burger King", Menu option 2, "A&W", Menu option 3, "A&W", Menu option 1, Menu option 6.
Outputs:
'Arby's' removed, incorrect # of opponents, 'Burger King' added, 'A&W' added, 'A&W' removed,
Restaurant list: McDonald's, Little Caesar's, Pizza Hut, Sonic, Winger's, Panda Express, In-N-Out Burger, Burger King.

Test Case Three
Inputs: Menu option 2, "A&W", Menu option 5, Menu option 3, "A&W", Menu option 5, tournament selections: #2, #2, #2, #2, #2, #2, #2 
Outputs:
'A&W' added, invalid # of opponents, 'A&W' removed
In-N-Out Burger is the winner!
*/
int main()
{
	vector<string> restaurants;
	const int TOURNAMENT_OPTION = 5;
	const int QUIT_OPTION = 6;
	const int DISPLAY_OPTION = 1;
	int selection = 0;
	srand(time(0));

	restaurants.push_back("McDonald's");
	restaurants.push_back("Little Caesar's");
	restaurants.push_back("Arby's");
	restaurants.push_back("Pizza Hut");
	restaurants.push_back("Sonic");
	restaurants.push_back("Winger's");
	restaurants.push_back("Panda Express");
	restaurants.push_back("In-N-Out Burger");

	while (selection < TOURNAMENT_OPTION || selection > QUIT_OPTION)
	{
		cout << endl << "1 - Display all restaurants";
		cout << endl << "2 - Add a restaurant";
		cout << endl << "3 - Remove a restaurant";
		cout << endl << "4 - Shuffle the vector";
		cout << endl << "5 - Begin the tournament";
		cout << endl << "6 - Quit the program";
		cout << endl << "Input: ";
		cin >> selection;

		if (cin.fail() || selection > QUIT_OPTION || selection < DISPLAY_OPTION)
		{
			incorrectInput();
		}
		else
		{
			selection = menuSelection(selection, restaurants);
			if (selection == 0)
			{
				cout << endl << endl;
				system("pause");
				return 0;
			}
		}
	}

}
int menuSelection(int selection, vector<string>& restaurants)
{
	string winner;
	string toFind = "";

	switch (selection)
	{
	case 1:
		displayRestaurants(restaurants);
		break;
	case 2:
		addRestaurant(restaurants);
		break;
	case 3:
		cout << "Which restaurant would you like to remove?: ";
		cin.ignore();
		getline(cin, toFind);

		cout << removeRestaurant(restaurants, toFind) << endl;
		break;
	case 4:
		shuffleVector(restaurants);
		break;
	case 5:
		winner = tournament(restaurants);

		if (winner != "invalid")
		{
			cout << winner << " is the winner!!";
			return 0;
		}
		else
		{
			cout << "Incorrect amount of opponents!" << endl;
			return 1;
		}
			
		system("pause");
		break;
	case 6:
		cout << endl << "--Exiting--" << endl;
		system("pause");
		break;
	}
}
void displayRestaurants(const vector<string> restaurants)
{
	for (int length = 0; length < restaurants.size(); ++length)
	{
		cout << restaurants[length];

		if (!(length + 1 == restaurants.size()))
		{
			cout << ", ";
		}
	}
}
void addRestaurant(vector<string>& restaurants)
{
	string newRestaurant;

	cout << "Restaurant name: ";
	cin.ignore();
	getline(cin, newRestaurant);

	if (findRestaurant(restaurants, newRestaurant) != FALSE_RETURN_VALUE)
	{
		cout << "'" << newRestaurant << "' already exists." << endl;
	}
	else
	{
		restaurants.push_back(newRestaurant);
		cout << "'" << newRestaurant << "' added to restaurants." << endl;
	}
}
string removeRestaurant(vector<string>& restaurants, string toFind)
{
	string removedRestaurant = "Restaurant not found.";
	int restaurantSubscript = 0;
	restaurantSubscript = findRestaurant(restaurants, toFind);

	if (restaurantSubscript != FALSE_RETURN_VALUE)
	{
		restaurants.erase(restaurants.begin() + restaurantSubscript);
		removedRestaurant = "'" + toFind + "' Removed.";
	}
	return removedRestaurant;
}
void shuffleVector(vector<string>& restaurants)
{

	int randomSubscriptOne = 0;
	int randomSubscriptTwo = 0;
	string tempString = "";

	for (int i = 0; i < ARBITRARY_ITERATION_NUMBER; ++i)
	{
		randomSubscriptOne = rand() % restaurants.size();
		randomSubscriptTwo = rand() % restaurants.size();

		tempString = restaurants[randomSubscriptOne];
		restaurants[randomSubscriptOne] = restaurants[randomSubscriptTwo];
		restaurants[randomSubscriptTwo] = tempString;
	}
	cout << endl << "List has been shuffled!" << endl;
}
string tournament(vector<string>& restaurants)
{
	const int OPTION_ONE = 1;
	const int OPTION_TWO = 2;
	int selection = 0;
	int halfOfTheRestaurants = restaurants.size() / 2;
	int size = restaurants.size();
	int roundIterator = 1;
	int power = checkIfIsPower(size);

	if (power != FALSE_RETURN_VALUE)
	{
		for (int i = 1; size > 1; ++i)
		{
			cout << endl << "Which restaurant do you prefer?" << endl;
			cout << "Match " << i << "/" << halfOfTheRestaurants << " Round " << roundIterator << "/" << power << endl;
			cout << "#1: " << restaurants[i - 1] << endl;
			cout << "#2: " << restaurants[i] << endl << "Input: ";
			cin >> selection;

			if (cin.fail() || selection < OPTION_ONE || selection > OPTION_TWO)
			{
				incorrectInput();
				--i;
			}
			else if (selection == OPTION_ONE)
			{
				removeRestaurant(restaurants, restaurants[i]);
				--size;
			}
			else if (selection == OPTION_TWO)
			{
				removeRestaurant(restaurants, restaurants[i - 1]);
				--size;
			}

			if (size == halfOfTheRestaurants)
			{
				i = 0;
				halfOfTheRestaurants = restaurants.size() / 2;
				++roundIterator;
			}
		}
		return restaurants[0];
	}
	else
	{
		
		return "invalid";
	}
}
int checkIfIsPower(int numberToCheck)
{
	const int NUMBER_TO_EXPONENT = 2;
	for (int power = 1; power < ARBITRARY_ITERATION_NUMBER; ++power)
	{
		if (numberToCheck == pow(NUMBER_TO_EXPONENT, power))
		{
			return power;
		}
	}
	return -1;
}
int findRestaurant(vector<string>& restaurants, string toFind)
{
	const int BEGINNING_OF_LIST = -1;
	for (int i = restaurants.size() - 1; i > BEGINNING_OF_LIST; --i)
	{
		if (toFind == restaurants[i])
		{
			return i;
		}
	}
	return -1;
}
void incorrectInput()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << endl << "---Invalid Selection. Please select a number from the menu---" << endl;
}
