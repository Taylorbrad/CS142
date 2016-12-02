// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"
#include "Commercial.h"
#include "Residential.h"
using namespace std;
string getFileName()
{
	string fileName = "";

	cout << "Where should I read the data from? ";
	cin >> fileName;

	return fileName;
}
int main()
{
	string fileName = "";
	string fileNameTemp = "";
	ifstream toOpen;
	ofstream toWrite;
	//stringstream ss;
	//stringstream ss1;
	string address = "";
	string typeOfProperty = "";
	double value = 0;
	string valueString = "";
	double discount = 0;
	string discountString = "";
	bool isRental = false;
	string isRentalString = "";
	bool isDiscounted = false;
	string isDiscountedString = "";
	bool isOccupied = false;
	string isOccupiedString = "";
	vector<Property*> properties;
	//vector<stringstream> badLinesSS;

	fileName = getFileName();
	//fileNameTemp = fileName + ".txt";
	toOpen.open(fileName);
	
		//cout << endl << fileNameTemp;
	if (toOpen.is_open())
	{
		for (int id = 0; !toOpen.eof(); ++id)
		{
			cout << endl << "lmao";
			//getline(toOpen, ss, '\n'); //put the entire line in ss
				/*TODO: try pulling from ss instead of toOpen in the following lines */
			getline(toOpen, typeOfProperty, ' ');
			getline(toOpen, isRentalString, ' ');
			getline(toOpen, valueString, ' ');
			if (typeOfProperty == "Commercial")
			{

				getline(toOpen, isDiscountedString, ' ');
				getline(toOpen, discountString, ' ');
				getline(toOpen, address, '\n');

				Commercial* test = new Commercial(address, isDiscounted, isRental, discount, value, id);
				properties.push_back(test);
				cout << (*test).toString();
			}
			else if (typeOfProperty == "Residential")
			{
				getline(toOpen, isOccupiedString, ' ');
				getline(toOpen, address, '\n');

				Residential* test1 = new Residential(address, isOccupied, isRental, value, id);
				properties.push_back(test1);
				cout << test1->toString();
			}
			else
			{

				cout << "kkk" << valueString << " ";
				//badLinesSS.push_back(ss);
			}
		}
	}
	else
	{
		cout << "There was an error reading the file!";
	}
	//TODO: Open new file for writing to, and write the necessary output.
	toWrite.open((fileName + "OUT.txt"));

	if (toWrite.is_open())
	{

	}
	else
	{
		cout << "There was an error reading the file!";
	}
	system("pause");
}
