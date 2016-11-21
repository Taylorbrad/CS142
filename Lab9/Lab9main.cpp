#include <vector>
#include <iostream>
#include <string>
#include "Player.h"

int getMenuOption()
{
    int option = 0;
    
    cout << "1 - Show Players" << endl;
    cout << "2 - Add Player" << endl;
    cout << "3 - Add to Line-Up" << endl;
    cout << "4 - Show Line-Up" << endl;
    cout << "5 - Fight!" << endl;
    cout << "6 - Quit" << endl;
    cin >> option;
    
    return option
}

string displayPlayers(vector<Player*> allPlayers)
{
    
    ss << "--------------------------------";
    for (int i = 0; i < allPlayers.size(); ++i)
    {
        (*(allPlayers[i])).calculateRecord();
        if (i != 0)
        {
        ss << "-----------------";
        }
        ss << "#" << i + 1 << ": " << endl;
        ss << (*(allPlayers[i])).toString();
    }
    ss << "--------------------------------" << endl << endl;
    
    return ss;
}
void addPlayer(vector<Player*> allPlayers)
{
    string name;
    
    cout << "What is the name of the player?" << endl;
    getline(cin, name);
    //Check if name already exists
    if (checkIfNameExists)
    {
        Player* newGuy(name);
        allPlayers.push_back(newGuy);
        cout << "New player \"" << name << "\" added!" << endl; 
    }
    else
    {
        cout << "Name already Exists!" << endl;
    }
    
    
}
bool checkIfNameExists(string name, vector<Player*> allPlayers)
{
    for (int i = 0; i < allPlayers.size(); ++i)
    {
        if (name == (*(allPlayers[i])).name)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    const int SHOW_PLAYERS = 1;
    const int ADD_PLAYER = 2;
    const int ADD_TO_LINE_UP = 3; 
    const int SHOW_LINE_UP = 4;
    const int FIGHT = 5;
    const int QUIT = 6;
    
    int selection = 0;
    vector<Player*> listOfPlayers;
    vector<Player*> lineUpOfPlayers;
    
    selection = getMenuOption();
    
    switch(selection)
    {
        case SHOW_PLAYERS:
        cout << displayPlayers(listOfPlayers);
        break;
        
        case ADD_PLAYER:
        addPlayer(listOfPlayers);
        break;
        
        case ADD_TO_LINE_UP:
        
        break;
        
        case SHOW_LINE_UP:
        
        break;
        
        case FIGHT:
        
        break;
        
        case QUIT:
        system("pause");
        return 0;
        break;
    }
}
