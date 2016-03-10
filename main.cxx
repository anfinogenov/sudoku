#include <iostream>
#include <ctime>
#include <cstdlib>

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

/*
void str_generator (sudoku_t & field, int num)
{
    int temp[9] = {};

    for (int i = 0; i < 9; i++) temp[i] = i+1; //fills temp array with 1..9

    for (int i = 0; i < 9; i++)
    {
        int temp_rand = rand()%9;
        if (temp[temp_rand] != 0)
        {
            field.array[num][i] = temp[temp_rand];
            temp[temp_rand] = 0;
        }
        else i--;
    }
}
*/

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
                    system("clear");
                    print(field);
                }

}

/*
void advanced_generator (sudoku_t & field)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            field.array[i][j] = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int temp_rand = rand()%9 + 1;
            if (uniqueCheck(field, i, j, temp_rand))
                field.array[i][j] = temp_rand;
            else j--;
            //system("clear");
            //print(field);
        }
    }
}
*/

/* j
void advanced_generator_v2 (sudoku_t & field)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            field.array[i][j] = 0; //fills field with zeros

    int counter = 1;
    for (int n = 1; n <= 9;)
    {
        int i = rand()%9;
        int j = rand()%9;
        if (uniqueCheck(field, i, j, n) && (field.array[i][j] == 0))
        {
            field.array[i][j] = n;
            counter++;
        }
        if (counter == 9)
        {
            n++;
            counter = 1;
        }
        system("clear");
        print(field);
    }
}
*/

//TODO: генерировать поле поквадратно

/*
void generate(sudoku_t & field)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++) str_generator(field, i);
}
*/



int main()
{
    sudoku_t field;
    advanced_generator_v3(field);
    print(field);

    return 0;
}
