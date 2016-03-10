#include <iostream>
#include <ctime>
#include <cstdlib>

const bool debug = 1;

using namespace std;

typedef struct sudoku_t {
    int array[9][9];
} sudoku_t;

void print(sudoku_t field)
{
    int counterLine = 0;
    int counterCol = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << field.array[i][j] << " ";
            if (++counterCol%3 == 0) cout << "\t";
        }
        cout << endl;
        if (++counterLine%3 == 0) cout << endl;
    }
}

bool uniqueCheck(sudoku_t field, int x, int y, int number)
//checks, if there are any contradictions with sudoku logic
{
    for (int j = 0; j < 9; j++) //string checker
        if (field.array[x][j] == number) return false;

    for (int i = 0; i < 9; i++) //column checker
        if (field.array[i][y] == number) return false;

    { //square checker (little tricky move to check 9 field squares 3*3)
        int i = x - x%3;
        int j = y - y%3;
        for (int m = 0; m < 3; m++) //three times row from x
            for (int n = 0; n < 3; n++) //three times col from y
                if (field.array[i+m][j+n] == number)
                    return false;
    }
    return true;
}

void advanced_generator_v3 (sudoku_t & field)
{
    srand(time(NULL));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            field.array[i][j] = 0; // inits field with zeros

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int m = 0; m < 3; m++)
                for (int n = 0; n < 3;)
                {
                    int temp_rand = rand()%9 + 1;
                    if(uniqueCheck(field, (i*3)+m, (j*3)+n, temp_rand))
                    {
                        field.array[i*3+m][j*3+n] = temp_rand;
                        n++;
                    }
                    if(debug)
                    {
                        system("clear");
                        print(field);
                    }
                }

}

int main()
{
    sudoku_t field;
    advanced_generator_v3(field);
    print(field);

    return 0;
}
