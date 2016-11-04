// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

void menuSelection(int selection, vector<string>& restaurants);
void displayRestaurants(const vector<string> restaurants);
void addRestaurant(vector<string>& restaurants);
void removeRestaurant(vector<string>& restaurants, string toFind);
void shuffleVector(vector<string>& restaurants);
void tournament(vector<string>& restaurants);

int main()
{
    vector<string> restaurants;
    int selection = 0;
    srand(time(0));
    
    restaurants.push_back("A");
    restaurants.push_back("B");
    restaurants.push_back("C");
    restaurants.push_back("D");
    restaurants.push_back("E");
    restaurants.push_back("F");
    restaurants.push_back("G");
    restaurants.push_back("H");
    
    while (selection < 5)
    {
        cout << endl << "1 - Display all restaurants";
        cout << endl << "2 - Add a restaurant";
        cout << endl << "3 - Remove a restaurant";
        cout << endl << "4 - Shuffle the vector";
        cout << endl << "5 - Begin the tournament";
        cout << endl << "6 - Quit the program";
        cout << endl << "Input: ";
        cin >> selection;
        
        if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl << "---Invalid Selection. Please select a number from the menu---" << endl;

		}
		else
		{
		    menuSelection(selection, restaurants);
		}
        
    }
    
}
void menuSelection(int selection, vector<string>& restaurants)
{
    string toFind = "";
    
    switch(selection)
    {
    case 1:
    displayRestaurants(restaurants);
    break;
    case 2:
    addRestaurant(restaurants);
    break;
    case 3:
    
    cout << "Which restaurant would you like to remove? :";
    cin.ignore();
    getline(cin, toFind);
    
    removeRestaurant(restaurants, toFind);
    break;
    case 4:
    shuffleVector(restaurants);
    break;
    case 5:
    tournament(restaurants);
    break;
    case 6:
    //DONE
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
    //cin >> newRestaurant;
    
    if (find(restaurants.begin(), restaurants.end(), newRestaurant) != restaurants.end())
    {
        cout << "'" << newRestaurant <<"' already exists.";
    }
    else
    {
        restaurants.push_back(newRestaurant);
        cout << "'" << newRestaurant << "' added to restaurants." << endl;
    }
}
void removeRestaurant(vector<string>& restaurants, string toFind)
{
    if (find(restaurants.begin(), restaurants.end(), toFind) != restaurants.end())
    {
        //Erase the "removed" elements.
        restaurants.erase(find(restaurants.begin(), restaurants.end(), toFind));
        cout << "'" << toFind << "' removed from restaurants." << endl;
    }
    else
    {
        cout << "'" << toFind << "' not found" << endl;
    }
}
void shuffleVector(vector<string>& restaurants)
{
    int randomSubscriptOne = 0;
    int randomSubscriptTwo = 0;
    string tempString = "";
    
    for (int i = 0; i < 100; ++i)
    {
        randomSubscriptOne = rand() % restaurants.size();
        randomSubscriptTwo = rand() % restaurants.size();
        
        tempString = restaurants[randomSubscriptOne];
        restaurants[randomSubscriptOne] = restaurants[randomSubscriptTwo];
        restaurants[randomSubscriptTwo] = tempString;
    }
    cout << endl << "List has been shuffled!";
}
void tournament(vector<string>& restaurants)
{
    int selection = 0;
    int halfOfTheRestaurants = restaurants.size() / 2;
    
    //for (
    for (int i = 1; restaurants.size() > 1; ++i)
    {
        cout << "#1: " << restaurants[i - 1] << endl;
        cout << "#2: " << restaurants[i] << endl;
        cout << "Which restaurant do you prefer? (1 or 2): ";
        cin >> selection;
        
        if (cin.fail() || selection < 1 || selection > 2)
		{
		    if (cin.fail())
			{
        	    cin.clear();
    	        cin.ignore(1000, '\n');
		    }
			cout << endl << "---Invalid Selection. Please select a number from the menu---" << endl;
			--i;
		}
		else
		{
		    switch (selection)
		    {
		        case 1:
		            removeRestaurant(restaurants, restaurants[i]);
		        break;
		        case 2:
		            removeRestaurant(restaurants, restaurants[i - 1]);
		        break;
		    }
		}
		if (restaurants.size() == halfOfTheRestaurants)
		{
		    i = 0;
		    halfOfTheRestaurants = restaurants.size() / 2;
		}
    }
    cout << restaurants[1] << " is the winner!!" << endl;
}
