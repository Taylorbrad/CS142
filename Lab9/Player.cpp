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

Player::~Player(){}
