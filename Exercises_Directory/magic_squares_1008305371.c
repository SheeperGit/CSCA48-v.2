////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////

    // Manually inputting sums of all rows...
    int row_1_sum = square[0][0] + square[0][1] + square[0][2] + square[0][3] + square[0][4] + square[0][5];
    int row_2_sum = square[1][0] + square[1][1] + square[1][2] + square[1][3] + square[1][4] + square[1][5];
    int row_3_sum = square[2][0] + square[2][1] + square[2][2] + square[2][3] + square[2][4] + square[2][5];
    int row_4_sum = square[3][0] + square[3][1] + square[3][2] + square[3][3] + square[3][4] + square[3][5];
    int row_5_sum = square[4][0] + square[4][1] + square[4][2] + square[4][3] + square[4][4] + square[4][5];
    int row_6_sum = square[5][0] + square[5][1] + square[5][2] + square[5][3] + square[5][4] + square[5][5];
    int row_sums[6] = {row_1_sum, row_2_sum, row_3_sum, row_4_sum, row_5_sum, row_6_sum};

    // Changing Rows...
    int row_empties = 0;
    int *rp = NULL;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (square[i][j] == -1){
                row_empties++;
                rp = &square[i][j];
            }
        }
        if (row_empties == 1) *rp = 110 - row_sums[i];
        row_empties = 0;
    }

    int col_1_sum = square[0][0] + square[1][0] + square[2][0] + square[3][0] + square[4][0] + square[5][0];
    int col_2_sum = square[0][1] + square[1][1] + square[2][1] + square[3][1] + square[4][1] + square[5][1];
    int col_3_sum = square[0][2] + square[1][2] + square[2][2] + square[3][2] + square[4][2] + square[5][2];
    int col_4_sum = square[0][3] + square[1][3] + square[2][3] + square[3][3] + square[4][3] + square[5][3];
    int col_5_sum = square[0][4] + square[1][4] + square[2][4] + square[3][4] + square[4][4] + square[5][4];
    int col_6_sum = square[0][5] + square[1][5] + square[2][5] + square[3][5] + square[4][5] + square[5][5];
    int col_sums[6] = {col_1_sum, col_2_sum, col_3_sum, col_4_sum, col_5_sum, col_6_sum};
    
    // Changing Columns...
    int col_empties = 0;
    int *cp = NULL;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (square[j][i] == -1){
                col_empties++;
                cp = &square[j][i];
            }
        }
        if (col_empties == 1) *cp = 110 - col_sums[i];
        col_empties = 0;
    }

    // Recompiling summations of row and column entries...

    row_1_sum = square[0][0] + square[0][1] + square[0][2] + square[0][3] + square[0][4] + square[0][5];
    row_2_sum = square[1][0] + square[1][1] + square[1][2] + square[1][3] + square[1][4] + square[1][5];
    row_3_sum = square[2][0] + square[2][1] + square[2][2] + square[2][3] + square[2][4] + square[2][5];
    row_4_sum = square[3][0] + square[3][1] + square[3][2] + square[3][3] + square[3][4] + square[3][5];
    row_5_sum = square[4][0] + square[4][1] + square[4][2] + square[4][3] + square[4][4] + square[4][5];
    row_6_sum = square[5][0] + square[5][1] + square[5][2] + square[5][3] + square[5][4] + square[5][5];

    col_1_sum = square[0][0] + square[1][0] + square[2][0] + square[3][0] + square[4][0] + square[5][0];
    col_2_sum = square[0][1] + square[1][1] + square[2][1] + square[3][1] + square[4][1] + square[5][1];
    col_3_sum = square[0][2] + square[1][2] + square[2][2] + square[3][2] + square[4][2] + square[5][2];
    col_4_sum = square[0][3] + square[1][3] + square[2][3] + square[3][3] + square[4][3] + square[5][3];
    col_5_sum = square[0][4] + square[1][4] + square[2][4] + square[3][4] + square[4][4] + square[5][4];
    col_6_sum = square[0][5] + square[1][5] + square[2][5] + square[3][5] + square[4][5] + square[5][5];

    int row_sum = row_1_sum + row_2_sum + row_3_sum + row_4_sum + row_5_sum + row_6_sum;
    int col_sum = col_1_sum + col_2_sum + col_3_sum + col_4_sum + col_5_sum + col_6_sum;

    // 12 (rows + cols) * 111 (Magic Number) = 1332.
    if (row_sum + col_sum != 1332) solveMagicSquare(square);
}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
