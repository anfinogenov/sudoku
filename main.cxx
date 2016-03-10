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

void generator (sudoku_t & field)
{
    srand(time(NULL));

    for (int coord_x = 0; coord_x < 9; coord_x++)
        for (int coord_y = 0; coord_y < 9; coord_y++)
            field.array[coord_x][coord_y] = 0; // inits field with zeros

    //outer coords for 3*3 squares, inner coords for numbers inside, 3*3 too

    for (int outer_x = 0; outer_x < 3; outer_x++)
        for (int outer_y = 0; outer_y < 3; outer_y++)
            for (int inner_x = 0; inner_x < 3; inner_x++)
                for (int inner_y = 0; inner_y < 3;) //4 loops for square
                {
                    int coord_x = outer_x*3 + inner_x;
                    int coord_y = outer_y*3 + inner_y;

                    int temp_rand = rand()%9 + 1;
                    if(uniqueCheck(field, coord_x, coord_y, temp_rand))
                    {
                        field.array[coord_x][coord_y] = temp_rand;
                        inner_y++;
                    }

                    if(debug) { system("clear"); print(field); }
                    //prints full field after every generation step
                }

}

int main()
{
    sudoku_t field;
    generator(field);
    print(field);

    return 0;
}
