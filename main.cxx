#include <iostream>
#include <ctime>
#include <cstdlib>

const bool debug = 0;
const int numbers1to9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

using namespace std;

typedef struct Sudoku {
    int array[9][9];
<<<<<<< HEAD
    bool generate() { while(!generator()); } //field generation complete when generator return true
    bool generator();
    bool generationFailureCheck (int coord_x, int coord_y);
    bool generateSquare3x3 (int sq_coord_x, int sq_coord_y);
    bool uniqueCheck(int coord_x, int coord_y, int number);
    void print();
} Sudoku;

void Sudoku::print() {
=======
} sudoku_t;

void fieldInit (sudoku_t & field);
bool generator (sudoku_t & field);
bool generateSquare3x3 (sudoku_t & field, int sq_coord_x, int sq_coord_y);
bool generationFailureCheck (sudoku_t field, int coord_x, int coord_y);
void print (sudoku_t field);
bool uniqueCheck (sudoku_t field, int coord_x, int coord_y, int number);

void fieldInit (sudoku_t & field)
{
>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0
    for (int coord_x = 0; coord_x < 9; coord_x++)
    {
        for (int coord_y = 0; coord_y < 9; coord_y++)
<<<<<<< HEAD
        {
            cout << this->array[coord_x][coord_y] << " ";
            if (coord_y % 3 == 2) cout << "\t"; //if printed 3 numbers in string do "\t"
        }
        cout << endl; //if printed full string do "\n"
        if (coord_x % 3 == 2) cout << endl; //if printed 3 strings do additional "\n"
    }
}
bool Sudoku::uniqueCheck(int coord_x, int coord_y, int number) {
    //checks, if there are any contradictions with sudoku logic
    for (int inner_y = 0; inner_y < 9; inner_y++) //string checker
        if (this->array[coord_x][inner_y] == number) return false;
        //if number already exists in string returns false;

    for (int inner_x = 0; inner_x < 9; inner_x++) //string checker
        if (this->array[inner_x][coord_y] == number) return false;
        //if number already exists in column returns false;

    { //square checker
        int sq_coord_x = coord_x - coord_x%3; //parse 0 or 3 or 6 from input coord X
        int sq_coord_y = coord_y - coord_y%3; //parse 0 or 3 or 6 from input coord Y
        for (int inner_x = 0; inner_x < 3; inner_x++) //three times right from sq_coord_x
            for (int inner_y = 0; inner_y < 3; inner_y++) //three times down from sq_coord_y
                if (number != 0) //why we need to check 0?
                    if (this->array[sq_coord_x + inner_x][sq_coord_y + inner_y] == number)
                        return false;
    }
    return true;
}
bool Sudoku::generateSquare3x3 (int sq_coord_x, int sq_coord_y) {
=======
            field.array[coord_x][coord_y] = 0; // inits field with zeros
}

bool generator (sudoku_t & field) //this function generates field by squares
{
    fieldInit (field);

    //outer coords for 3*3 squares, inner coords for numbers inside, 3*3 too
    for (int outer_x = 0; outer_x < 3; outer_x++)
        for (int outer_y = 0; outer_y < 3; outer_y++)
            if (!generateSquare3x3(field, outer_x*3, outer_y*3))
            //if statement starts generate3x3 function, and if it returns false generator stops
                return false;
    return true;
}

bool generateSquare3x3 (sudoku_t & field, int sq_coord_x, int sq_coord_y)
{
>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0
    for (int inner_x = 0; inner_x < 3; inner_x++) //inner square coordinates
        for (int inner_y = 0; inner_y < 3;)
        {
            int coord_x = sq_coord_x + inner_x;
            int coord_y = sq_coord_y + inner_y;

<<<<<<< HEAD
            if (this->generationFailureCheck(coord_x, coord_y))
=======
            if (generationFailureCheck(field, coord_x, coord_y))
>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0
                return false; //generation failed

            int temp_rand = rand()%9 + 1;
            if (this->uniqueCheck(coord_x, coord_y, temp_rand))
            {
                this->array[coord_x][coord_y] = temp_rand;
                inner_y++;
            }
<<<<<<< HEAD
            if (debug) { system("clear"); this->print(); }
            //prints full field after every generation step
        }
=======
            if (debug) { system("clear"); print(field); }
            //prints full field after every generation step
        }

>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0
    return true; //generation successful
}
bool Sudoku::generator () {
    //this function generates field by squares
    for (int coord_x = 0; coord_x < 9; coord_x++)
        for (int coord_y = 0; coord_y < 9; coord_y++)
            this->array[coord_x][coord_y] = 0; // inits field with zeros

<<<<<<< HEAD
    //outer coords for 3*3 squares, inner coords for numbers inside, 3*3 too
    for (int outer_x = 0; outer_x < 3; outer_x++)
        for (int outer_y = 0; outer_y < 3; outer_y++)
            if (!this->generateSquare3x3(outer_x*3, outer_y*3))
            //if statement starts generate3x3 function, and if it returns false generator stops
                return false;
    return true;
}
bool Sudoku::generationFailureCheck (int coord_x, int coord_y) {
    //returns true, if there is no numbers we can place in that coords
    bool failure = false;
    for (int i = 0; i < 9; i++)
    {
        failure = failure | this->uniqueCheck(coord_x, coord_y, numbers1to9[i]);
        //if there is no number in 1..9 that we can place, failure variable doesn't change and function returns !failure -> true
        if (failure) break; //if we found at least 1 number in 1..9, stop loop and return false
=======
bool generationFailureCheck (sudoku_t field, int coord_x, int coord_y)
//returns true, if there is no numbers we can place in that coords
{
    bool failure = false;
    for (int i = 0; i < 9; i++)
    {
        failure = failure | uniqueCheck(field, coord_x, coord_y, numbers1to9[i]);
        //if there is no number in 1..9 that we can place, failure variable doesn't change and function returns !failure -> true
        if (failure) break; //if we found at least 1 number in 1..9, stop loop and return false
    }
    return !failure;
}

bool uniqueCheck(sudoku_t field, int coord_x, int coord_y, int number)
//checks, if there are any contradictions with sudoku logic
{
    for (int inner_y = 0; inner_y < 9; inner_y++) //string checker
        if (field.array[coord_x][inner_y] == number) return false;
        //if number already exists in string returns false;

    for (int inner_x = 0; inner_x < 9; inner_x++) //string checker
        if (field.array[inner_x][coord_y] == number) return false;
        //if number already exists in column returns false;

    { //square checker
        int sq_coord_x = coord_x - coord_x%3; //parse 0 or 3 or 6 from input coord X
        int sq_coord_y = coord_y - coord_y%3; //parse 0 or 3 or 6 from input coord Y
        for (int inner_x = 0; inner_x < 3; inner_x++) //three times right from sq_coord_x
            for (int inner_y = 0; inner_y < 3; inner_y++) //three times down from sq_coord_y
                if (number != 0) //why we need to check 0?
                    if (field.array[sq_coord_x + inner_x][sq_coord_y + inner_y] == number)
                        return false;
    }
    return true;
}

void print(sudoku_t field)
{
    for (int coord_x = 0; coord_x < 9; coord_x++)
    {
        for (int coord_y = 0; coord_y < 9; coord_y++)
        {
            cout << field.array[coord_x][coord_y] << " ";
            if (coord_y % 3 == 2) cout << "\t"; //if printed 3 numbers in string do "\t"
        }
        cout << endl; //if printed full string do "\n"
        if (coord_x % 3 == 2) cout << endl; //if printed 3 strings do additional "\n"
>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0
    }
    return !failure;
}

int main()
{
    srand(time(NULL));
<<<<<<< HEAD

    Sudoku field;
    field.generate(); //field generation complete when generator return true
    field.print();

    if (debug) {
        Sudoku field[100];
        for(int i = 0; i < 100; i++)
            field[i].generate(); //field generation complete when generator return true
        field[0].print();
    }
=======
    sudoku_t field;

    while (!generator(field)); //field generation complete when generator return true

    print(field);
>>>>>>> 41baebbe566cb653f0137ef7ad5d40c668aaf1e0

    return 0;
}
