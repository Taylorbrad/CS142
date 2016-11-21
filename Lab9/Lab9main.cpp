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
void addPlayer(vector<Player*>& allPlayers)
{
    string name = getName();
    //Check if name already exists
    if (checkIfNameExists(name, allPlayers) != -1)
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
int checkIfNameExists(string name, vector<Player*> allPlayers)
{
    for (int i = 0; i < allPlayers.size(); ++i)
    {
        if (name == (*(allPlayers[i])).name)
        {
            return i;
        }
    }
    return -1;
}
string getName()
{
    string name;
    
    cout << "What is the name of the player you want to add?" << endl;
    getline(cin, name);
    
    return name;
}
void addToLineUp(vector<Player*> allPlayers, vector<Player*>& lineUp)
{
    string name = getName();
    int subscriptForName = checkIfNameExists(name, allPlayers);
    if (subscriptForName != -1)
    {
        Player* newPlayerInQueue = (*(allPlayers[subscriptForName]));
        lineUp.push_back(newPlayerInQueue);
    }
    else
    {
        cout << "Player not found!" << endl;
    }
}
void displayLineUp(vector<Player>* lineUp)
{
    cout << endl;
    cout << "---------------Current Line-Up---------------" << endl;
    ciut << "1: ";
    for (int i = 0; i < lineUp.size(); ++i)
    {
        cout << (*(lineUp[i])).name;
        if (i == (lineUp.size() - 1))
        {
            cout << ", " << i << ": ";
        }
        else
        {
            cout << ".";
        }
    }
}
int getWhoWon(int firstThrow, int secondThrow)
{
    if (firstThrow == 1)
    {
        if(secondThrow == 1)
        {
            return 0;
        }
        else if (secondThrow == 2)
        {
            return 2;
        }
        else if (secondThrow == 3)
        {
            return 1;
        }
    }
    else if (firstThrow == 2)
    {
        if(secondThrow == 1)
        {
            return 1;
        }
        else if (secondThrow == 2)
        {
            return 0;
        }
        else if (secondThrow == 3)
        {
            return 2;
        }
    }
    else if (firstThrow == 3)
    {
        if(secondThrow == 1)
        {
            return 2;
        }
        else if (secondThrow == 2)
        {
            return 1;
        }
        else if (secondThrow == 3)
        {
            return 0;
        }
    }
}
void fight(vector<Player*>& lineUp)
{
    int playerOneThrow = 0;
    int playerTwoThrow = 0;
    int whoWon = 0;
    int whoLost = 1;
    playerOneThrow = (*(lineup[0])).getRPSThrow();
    playerTwoThrow = (*(lineup[1])).getRPSThrow();
    
    if ((*(lineUp[0])).name  == (*(lineUp[1])).name)
    {
        cout << "It's a Draw!" << endl;
        (*(lineUp[0])).draws += 1;
        (*(lineUp[0])).games += 1;
        removePlayers(lineUp);
    }
    else
    {
        whoWon = getWhoWon(playerOneThrow, playerTwoThrow);
        if (whoWon == 1)
        {
            whoLost = 2;
        }
        if (whoWon == 0)
        {
            cout << "It's a Draw!" << endl;
            (*(lineUp[0])).draws += 1;
            (*(lineUp[0])).games += 1;
            (*(lineUp[1])).draws += 1;
            (*(lineUp[1])).games += 1;
            removePlayers(lineUp);
        }
        else
        {
            cout << "Fight initiated between Name1 and Name2!" << endl << endl;
            cout << (*(lineUp[0])).name << " throws " << playerOneThrow << endl;
            cout << (*(lineUp[1])).name << " throws " << playerTwoThrow << endl << endl;
            cout << (*(lineUp[whoWon - 1])).name << " is the winner!" endl;
            
            (*(lineUp[whoWon - 1])).wins += 1;
            (*(lineUp[whoWon - 1])).games += 1;
            (*(lineUp[whoLost - 1])).losses += 1;
            (*(lineUp[whoWon - 1])).games += 1;
            removePlayers(lineUp);
        }
    }
}
void removePlayers(vector<Player*>& lineUp)
{
    lineUp.erase(lineUp.begin());
    lineUp.erase(lineUp.begin());
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
        addToLineUp(listOfPlayers, lineUpOfPlayers);
        break;
        
        case SHOW_LINE_UP:
        displayLineUp(lineUpOfPlayers);
        break;
        
        case FIGHT:
        fight(lineUpOfPlayers);
        break;
        
        case QUIT:
        system("pause");
        return 0;
        break;
    }
}
