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
void removeRestaurant(vector<string>& restaurants);
void shuffleVector(vector<string>& restaurants);

int main()
{
    vector<string> restaurants;
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
    
    while (selection != 6)
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
    switch(selection)
    {
    case 1:
    displayRestaurants(restaurants);
    break;
    case 2:
    addRestaurant(restaurants);
    break;
    case 3:
    removeRestaurant(restaurants);
    break;
    case 4:
    shuffleVector(restaurants);
    break;
    case 5:
    
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
void removeRestaurant(vector<string>& restaurants)
{
    string toFind = "";
    
    cout << "Which restaurant would you like to remove? :";
    cin.ignore();
    getline(cin, toFind);
    //cin >> toFind;
    
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
