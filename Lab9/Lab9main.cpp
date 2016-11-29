/*

*/
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "Player.h"

int getMenuOption()
{
	int option = 0;

	cout << endl << "1 - Show Players" << endl;
	cout << "2 - Add Player" << endl;
	cout << "3 - Add to Line-Up" << endl;
	cout << "4 - Show Line-Up" << endl;
	cout << "5 - Fight!" << endl;
	cout << "6 - Quit" << endl;
	cin >> option;

	return option;
}
string getName()
{
	string name;

	cout << "What is the name of the player you want to add?" << endl;
	cin.ignore();
	getline(cin, name);

	return name;
}
string displayPlayers(vector<Player*> allPlayers)
{
	stringstream ss;
	ss << "---------------#1-----------------" << endl;

	for (int i = 0; i < allPlayers.size(); ++i)
	{
		if (i != 0)
		{
			ss << "--------" << "#" << i + 1 << "---------" << endl;
		}
		ss << (*(allPlayers[i])).toString();
	}
	ss << "----------------------------------" << endl << endl;
	return ss.str();
}
int checkIfNameExists(string name, vector<Player*> allPlayers) //Find Function, returns index for player
{
	int sizeOfArray = 0;
	sizeOfArray = allPlayers.size();
	
	if (sizeOfArray != 0)
	{
		for (int i = 0; i < allPlayers.size(); ++i)
		{
			if (name == (*(allPlayers[i])).getName())
			{
				return i;
			}
		}
	}

	return -1;
}
void addPlayer(vector<Player*>& allPlayers)
{
	int index = 0; 
	string name = getName();
	/*cout << "name: ";
	cin.ignore();
	getline(cin, name);*/
	//Check if name already exists
	index = checkIfNameExists(name, allPlayers);
	if (index == -1)
	{
		Player* newGuy = new Player(name);
		allPlayers.push_back(newGuy);
		cout << "New player \"" << name << "\" added!" << endl;
	}
	else
	{
		cout << "Name already Exists!" << endl;
	}
}


void addToLineUp(vector<Player*> allPlayers, vector<Player*>& lineUp)
{
	string name = getName();
	int subscriptForName = checkIfNameExists(name, allPlayers);
	if (subscriptForName != -1)
	{
		Player* newPlayerInQueue = allPlayers[subscriptForName];
		lineUp.push_back(newPlayerInQueue);
		cout << endl << "Player added to queue!" << endl;
	}
	else
	{
		cout << endl << "Player not found!" << endl;
	}
}
void displayLineUp(vector<Player*> lineUp)
{
	cout << endl;
	cout << "---------------Current Line-Up---------------" << endl;
	cout << "1: ";
	for (int i = 0; i < lineUp.size(); ++i)
	{
		cout << (*(lineUp[i])).getName();
		if (i < (lineUp.size() - 1))
		{
			cout << ", " << i + 2 << ": ";
		}
		else
		{
			cout << endl;
		}
	}
}
int getWhoWon(int firstThrow, int secondThrow)
{
	if (firstThrow == 1)
	{
		if (secondThrow == 1)
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
		if (secondThrow == 1)
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
		if (secondThrow == 1)
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
void removePlayers(vector<Player*>& lineUp)
{
	lineUp.erase(lineUp.begin());
	lineUp.erase(lineUp.begin());
}
void fight(vector<Player*>& lineUp)
{
	int playerOneThrow = 0;
	int playerTwoThrow = 0;
	int whoWon = 0;
	int whoLost = 1;
	string playerOneRPS = "";
	string playerTwoRPS = "";

	playerOneThrow = (rand() % 3) + 1;
	playerTwoThrow = (rand() % 3) + 1;
	cout << playerOneThrow << playerTwoThrow;

	if (lineUp.size() >= 2)
	{
		playerOneRPS = (*(lineUp[0])).getRPSThrow(playerOneThrow);
		cout << playerOneRPS;
		playerTwoRPS = (*(lineUp[1])).getRPSThrow(playerTwoThrow);
		cout << playerTwoRPS;
		system("pause");
		if ((*(lineUp[0])).getName() == (*(lineUp[1])).getName())
		{
			cout << "It's a Draw!" << endl;
			(*(lineUp[0])).addDraw();
			removePlayers(lineUp);
			system("pause");
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
				(*(lineUp[0])).addDraw();
				(*(lineUp[1])).addDraw();
				removePlayers(lineUp);
				system("pause");
			}
			else
			{
				cout << endl << "Fight initiated between " << (*(lineUp[0])).getName() << " and " << (*(lineUp[1])).getName() << endl << endl;
				cout << (*(lineUp[0])).getName() << " throws " << playerOneRPS << endl;
				cout << (*(lineUp[1])).getName() << " throws " << playerTwoRPS << endl << endl;
				cout << (*(lineUp[whoWon - 1])).getName() << " is the winner!" << endl;

				(*(lineUp[whoWon - 1])).addWin();
				(*(lineUp[whoLost - 1])).addLoss();
				removePlayers(lineUp);

			}
		}
	}
	else
	{
		cout << endl << "Not enough players in the queue!" << endl << endl;
	}
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

	/*
	Player* test1 = new Player("testOne"); 
	Player* test2 = new Player("testTwo");
	listOfPlayers.push_back(test1);
	listOfPlayers.push_back(test2);

	lineUpOfPlayers.push_back(test1);
	lineUpOfPlayers.push_back(test2);
	*/

	srand(time(0));
	while (true)
	{
		selection = getMenuOption();

		switch (selection)
		{
		case SHOW_PLAYERS: //1
			cout << displayPlayers(listOfPlayers);
			break;

		case ADD_PLAYER: //2
			addPlayer(listOfPlayers);
			break;

		case ADD_TO_LINE_UP: //3
			addToLineUp(listOfPlayers, lineUpOfPlayers);
			break;

		case SHOW_LINE_UP: //4
			displayLineUp(lineUpOfPlayers);
			break;

		case FIGHT: //5
			fight(lineUpOfPlayers);
			break;

		case QUIT: //6
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
}
