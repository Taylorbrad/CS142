// Example program
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const int LOWEST_SUBSCRIPT = 0;
    const int HIGHEST_SUBSCRIPT = 20;
    double plate[20][20];
    
    for (int i = LOWEST_SUBSCRIPT; i < HIGHEST_SUBSCRIPT; ++i)
    {
        for (int y = LOWEST_SUBSCRIPT; y < HIGHEST_SUBSCRIPT; ++y)
        {
            if (y == LOWEST_SUBSCRIPT || y == HIGHEST_SUBSCRIPT)
            {
                plate[i][y] = 0;
            }
            else if ((y < HIGHEST_SUBSCRIPT - 1 && y > LOWEST_SUBSCRIPT) && (i == HIGHEST_SUBSCRIPT - 1 || i == LOWEST_SUBSCRIPT))
            {
                plate[i][y] = 100;
            }
            else
            {
                plate[i][y] = 0;
            }
            cout << setw(10) << fixed << setprecision(4) << ">[" << i << "," << y << "]" << plate[i][y];
        }
        cout << endl;
    }
}
