// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void menuSelection(int selection, vector<string>& restaurants);
void displayRestaurants(const vector<string> restaurants);
void addRestaurant(vector<string>& restaurants);
void removeRestaurant(vector<string>& restaurants);

int main()
{
    vector<string> restaurants;
    
    int selection = 0;
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
        
        menuSelection(selection, restaurants);
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
    cin >> newRestaurant;
    
    if (find(restaurants.begin(), restaurants.end(), newRestaurant) != restaurants.end())
    {
        cout << "Restaurant already exists.";
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
    cin >> toFind;
    
    if (find(restaurants.begin(), restaurants.end(), toFind) != restaurants.end())
    {
        //Erase the "removed" elements.
        restaurants.erase(find(restaurants.begin(), restaurants.end(), toFind));
        cout << "'" << newRestaurant << "' removed from restaurants." << endl;
    }
    }
    else
    {
        cout << "Restaurant not found.";
    }
}
void shuffleVector()
{
    
}
