// Example program
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int LOWEST_SUBSCRIPT = 0;
const int TABLE_DIMENSION = 20;

void populateArray(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION]);
void displayArray(double array[][TABLE_DIMENSION]);
void exportArrayToTable(double plate[][TABLE_DIMENSION]);
void updatePlates(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], double plateOld[][TABLE_DIMENSION]);
double getAverageOfNeighbors(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], int i, int y);
bool checkIfStableTemps(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], double plateOld[][TABLE_DIMENSION]);

int main()
{

	double plate[TABLE_DIMENSION][TABLE_DIMENSION];
	double plateOld[TABLE_DIMENSION][TABLE_DIMENSION];
	double plateDuplicate[TABLE_DIMENSION][TABLE_DIMENSION];
	bool check = false;

	populateArray(plate, plateDuplicate);

	cout << endl << "Printing Initial Plate:" << endl << endl;

	displayArray(plate);
	updatePlates(plate, plateDuplicate, plateOld);

	cout << endl << "Printing Plate After First Iteration:" << endl << endl;

	displayArray(plate);
	check = checkIfStableTemps(plate, plateDuplicate, plateOld);

	while (!check)
	{
		check = checkIfStableTemps(plate, plateDuplicate, plateOld);
		updatePlates(plate, plateDuplicate, plateOld);
	}
	cout << endl << "Printing Final Plate:" << endl << endl;
	displayArray(plate);
	exportArrayToTable(plate);
	system("pause");
}
void updatePlates(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], double plateOld[][TABLE_DIMENSION])
{

	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			plateOld[i][y] = plate[i][y];
		}
	}

	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			bool IsNotConstantTemperature = !((y == LOWEST_SUBSCRIPT || y == TABLE_DIMENSION - 1) || ((y < TABLE_DIMENSION - 1 && y > LOWEST_SUBSCRIPT) && (i == TABLE_DIMENSION - 1 || i == LOWEST_SUBSCRIPT)));

			if (IsNotConstantTemperature)
			{
				plate[i][y] = getAverageOfNeighbors(plate, plateDuplicate, i, y);
			}
		}
	}
	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			plateDuplicate[i][y] = plate[i][y];
		}
	}

}
double getAverageOfNeighbors(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], int i, int y)
{
	double average = 0;

	average = (plateDuplicate[i - 1][y] + plateDuplicate[i + 1][y] + plateDuplicate[i][y - 1] + plateDuplicate[i][y + 1]) / 4;
	return average;
}
void populateArray(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION])
{
	const double HOT_PART_TEMP = 100;
	const double COLD_PART_TEMP = 0;

	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			if (y == LOWEST_SUBSCRIPT || y == TABLE_DIMENSION - 1)
			{
				plateDuplicate[i][y] = COLD_PART_TEMP;
				plate[i][y] = COLD_PART_TEMP;
			}
			else if ((y < TABLE_DIMENSION - 1 && y > LOWEST_SUBSCRIPT) && (i == TABLE_DIMENSION - 1 || i == LOWEST_SUBSCRIPT))
			{
				plateDuplicate[i][y] = HOT_PART_TEMP;
				plate[i][y] = HOT_PART_TEMP;
			}
			else
			{
				plateDuplicate[i][y] = COLD_PART_TEMP;
				plate[i][y] = COLD_PART_TEMP;
			}
		}
	}
}
void displayArray(double array[][TABLE_DIMENSION])
{
	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			cout << setw(10) << fixed << setprecision(4) << array[i][y];
		}
		cout << endl;
	}
}
void exportArrayToTable(double array[][TABLE_DIMENSION])
{
	ofstream outFile;
	outFile.open("HotPlate.csv", ios::trunc);

	if (outFile.is_open())
	{
		cout << endl << "...Writing Information to File..." << endl << endl;
		for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
		{
			for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
			{
				outFile << fixed << setprecision(4) << array[i][y];
				if (y < 19)
				{
					outFile << ",";
				}
			}
			outFile << endl;
		}
	}
	else
	{
		cout << "There was an issue creating/opening the file.";
	}
}
bool checkIfStableTemps(double plate[][TABLE_DIMENSION], double plateDuplicate[][TABLE_DIMENSION], double plateOld[][TABLE_DIMENSION])
{
	const double LOWEST_ACCEPTABLE_CHANGE = .101;
	bool isTempStable = true;

	for (int i = LOWEST_SUBSCRIPT; i < TABLE_DIMENSION; ++i)
	{
		for (int y = LOWEST_SUBSCRIPT; y < TABLE_DIMENSION; ++y)
		{
			double difference = (plate[i][y] - plateOld[i][y]);

			if (!(difference < LOWEST_ACCEPTABLE_CHANGE))
			{
				isTempStable = false;
			}
		}
	}
	return isTempStable;

