// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menuSelection(int selection, vector<string>& restaurants);
void displayRestaurants(const vector<string> restaurants);
void addRestaurant(vector<string>& restaurants);

int main()
{
    vector<string> restaurants;
    
    int selection = 0;
    
    cout << endl << "1 - Display all restaurants";
    cout << endl << "2 - Add a restaurant";
    cout << endl << "3 - Remove a restaurant";
    cout << endl << "4 - Shuffle the vector";
    cout << endl << "5 - Begin the tournament";
    cout << endl << "6 - Quit the program";
    cin >> selection;
    
    menuSelection(selection, restaurants);
    
    
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
    
    restaurants.push_back(newRestaurant);
}
