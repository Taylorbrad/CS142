#pragma once //Figure out what this is also
#include <iostream>
#include <vector>
#include <string>
//#include <>
using namespace std;

class Player
{
    private:
            string name;
            int wins = 0;
            int losses = 0;
            int draws = 0;
            int games = 0;
            int rpsThrow = 0;
            double record = wins / games;
            
    public:
            //Constructor for player
            Player(string nameInput);
            calculateRecord();
            getRPSThrow(int randNumb);
            toString();
            addWin();
            addLoss();
            addDraw();
            /*Figure out what this does*/virtual ~Player();
            
            //function definitios here
};
