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

bool uniqueCheck(sudoku_t field, int input_x, int input_y, int number)
//checks, if there are any contradictions with sudoku logic
{
    for (int coord_y = 0; coord_y < 9; coord_y++) //column checker
        if (field.array[input_x][coord_y] == number) return false;

    for (int coord_x = 0; coord_x < 9; coord_x++) //string checker
        if (field.array[coord_x][input_y] == number) return false;

    { //square checker (little tricky move to check 9 field squares 3*3)
        int sq_coord_x = input_x - input_x%3;
        int sq_coord_y = input_y - input_y%3;
        for (int inner_x = 0; inner_x < 3; inner_x++) //three times row from x
            for (int inner_y = 0; inner_y < 3; inner_y++) //three times col from y
                if (number != 0)
                    if (field.array[sq_coord_x + inner_x][sq_coord_y + inner_y] == number)
                        return false;
    }
    return true;
}

bool generationFailureCheck (sudoku_t field, int coord_x, int coord_y)
//checks, if there is a generation failure
{
    /*
    for (int i = 1; i <= 9; i++)
        if (!uniqueCheck(field, coord_x, coord_y, i)) return true; //does not work
    */
    return false;
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

                    if (generationFailureCheck(field, coord_x, coord_y))
                    {
                        cout << "generation failed\n";
                        exit(-1);
                    }

                    int temp_rand = rand()%9 + 1;
                    if (uniqueCheck(field, coord_x, coord_y, temp_rand))
                    {
                        field.array[coord_x][coord_y] = temp_rand;
                        inner_y++;
                    }

                    if (debug) { system("clear"); print(field); }
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
