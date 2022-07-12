#include "printTwoDArrayt.h"
#include<iostream>

bool printTwoDArrayt(int **a, int n)
{  
    
    /* If a NULL pointer or negative n (array size) is passed, return false, 
    otherwise if print is successful return true. */
    if ((n < 0) || (a == nullptr))
        return false; 

    /* a can be a nxn matrix, the outer loop runs over the rows. 
    The inner loop runs over the columns of each row.
    A newline command is issued when all columns of each row are printed.*/

    /*Define the number of columns -1 to check, if the printed column was the last one
    If it was the last column in each row, don't print the whitespace*/

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << a[i][j];
            if (j!= n-1)
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return true;
}
