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
	if (this->games != 0)
	{
		this->record = this->wins / this->games;
	}
	else
	{
		this->record = 0;
	}
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

	ss << "Name: " << this->name << endl;
	ss << "Wins: " << this->wins << endl;
	ss << "Losses: " << this->losses << endl;
	ss << "Draws: " << this->draws << endl;
	ss << "Record: " << this->record << endl;

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
string Player::getName()
{
	return this->name;
}
Player::~Player(){}
