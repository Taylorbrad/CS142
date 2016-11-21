#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Player::Player(string nameInput)
{
    name = nameInput;
}
void Player::calculateRecord()
{
    this->record = this->wins / this->games;
}
string Player::displayPlayers(vector<Player*> allPlayers)
{
    stringstream ss;
    ss << endl;
    ss << "--------------------------------";
    calculateRecord();
    for (int i = 0; i < allPlayers.size(); ++i)
    {
        if (i != 0)
        {
        ss << "-----------------";
        }
        ss << "#" << i + 1 << ": " << endl;
        ss << (*(allPlayers[i])).name << endl;
        ss << "Wins: " << (*(allPlayers[i])).wins << endl;
        ss << "Losses: " << (*(allPlayers[i])).losses << endl;
        ss << "Draws: " << (*(allPlayers[i])).draws << endl;
        ss << "Record: " << (*(allPlayers[i])).record << endl;
    }
    ss << "--------------------------------" << endl << endl;
}
Player::~Player(){}
