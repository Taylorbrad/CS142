#include "Player.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;


Player::Player(string nameInput)
{
    name = nameInput;
}
void Player::calculateRecord()
{
    this->record = this->wins / this->games;
}
string Player::getRPSThrow(int randNumb)
{
    if (randNumb == 1)
    {
        return "Rock";
    }
    else if (randNumb == 2)
    {
        return "Paper";
    }
    else if (randNumb == 3)
    {
        return "Scissors";
    }
}
string Player::toString()
{
    Player::calculateRecord();
    stringstream ss;
    ss << (*(allPlayers[i])).name << endl;
    ss << "Wins: " << (*(allPlayers[i])).wins << endl;
    ss << "Losses: " << (*(allPlayers[i])).losses << endl;
    ss << "Draws: " << (*(allPlayers[i])).draws << endl;
    ss << "Record: " << (*(allPlayers[i])).record << endl;
    
    return ss.str();
}
void Player::addWin()
{
    ++this->games;
    ++this->wins;
}
void Player::addLoss()
{
    ++this->games;
    ++this->losses;
}
void Player::addDraw()
{
    ++this->games;
    ++this->draws;
}
Player::~Player(){}
