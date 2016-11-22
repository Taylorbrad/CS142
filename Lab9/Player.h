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
	double record = 0;

public:
	//Constructor for player
	Player(string nameInput);
	void calculateRecord();
	string getRPSThrow(int randNumb);
	string toString();
	void addWin();
	void addLoss();
	void addDraw();
	string getName();
	/*Figure out what this does*/virtual ~Player();

	//function definitios here
};
