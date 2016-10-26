// Example program
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int LOWEST_SUBSCRIPT = 0;
const int HIGHEST_SUBSCRIPT = 20;

void populateArray(double plate[][20], double plateDuplicate[][20]);
void displayArray(double plate[][20], double plateDuplicate[][20]);
void updatePlates(double plate[][20], double plateDuplicate[][20]);
double getAverageOfNeighbors(double plate[][20], double plateDuplicate[][20], int i, int y);

int main()
{
    
    double plate[20][20];
    double plateDuplicate[20][20];
    
    populateArray(plate, plateDuplicate);
    //displayArray(plate, plateDuplicate);
    
    for (int i = 0; i < 20; ++i)
    {
        //cout << endl;
    }
    
    updatePlates(plate, plateDuplicate);
    displayArray(plate, plateDuplicate);
    
}
void updatePlates(double plate[][20], double plateDuplicate[][20])
{
    
    for (int i = LOWEST_SUBSCRIPT; i < HIGHEST_SUBSCRIPT; ++i)
    {
        for (int y = LOWEST_SUBSCRIPT; y < HIGHEST_SUBSCRIPT; ++y)
        {
            bool IsNotConstantTemperature = !((y == LOWEST_SUBSCRIPT || y == HIGHEST_SUBSCRIPT - 1) || ((y < HIGHEST_SUBSCRIPT - 1 && y > LOWEST_SUBSCRIPT) && (i == HIGHEST_SUBSCRIPT - 1 || i == LOWEST_SUBSCRIPT)));
            
            if (IsNotConstantTemperature)
            {
                plate[i][y] = getAverageOfNeighbors(plate, plateDuplicate, i, y);
            }
        }
    }
}
double getAverageOfNeighbors(double plate[][20], double plateDuplicate[][20], int i, int y)
{
    double average = 0;
    
    average = (plateDuplicate[i - 1][y] + plateDuplicate[i + 1][y] + plateDuplicate[i][y - 1] + plateDuplicate[i][y + 1]) / 4;
    return average;
}
void populateArray(double plate[][20], double plateDuplicate[][20])
{
    for (int i = LOWEST_SUBSCRIPT; i < HIGHEST_SUBSCRIPT; ++i)
    {
        for (int y = LOWEST_SUBSCRIPT; y < HIGHEST_SUBSCRIPT; ++y)
        {
            if (y == LOWEST_SUBSCRIPT || y == HIGHEST_SUBSCRIPT - 1)
            {
                plateDuplicate[i][y] = 0;
                plate[i][y] = 0;
            }
            else if ((y < HIGHEST_SUBSCRIPT - 1 && y > LOWEST_SUBSCRIPT) && (i == HIGHEST_SUBSCRIPT - 1 || i == LOWEST_SUBSCRIPT))
            {
                plateDuplicate[i][y] = 100;
                plate[i][y] = 100;
            }
            else
            {
                plateDuplicate[i][y] = 0;
                plate[i][y] = 0;
            }
            //cout << setw(10) << fixed << setprecision(4) << ">[" << i << "," << y << "]" << plate[i][y];
        }
        //cout << endl;
    }
}
void displayArray(double plate[][20], double plateDuplicate[][20])
{
    for (int i = LOWEST_SUBSCRIPT; i < HIGHEST_SUBSCRIPT; ++i)
    {
        for (int y = LOWEST_SUBSCRIPT; y < HIGHEST_SUBSCRIPT; ++y)
        {
            cout << setw(10) << fixed << setprecision(4) << ">[" << i << "," << y << "]" << plate[i][y];
        }
        cout << endl;
    }
}
