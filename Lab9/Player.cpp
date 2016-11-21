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
string Player::getRPSThrow()
{
    
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
Player::~Player(){}
