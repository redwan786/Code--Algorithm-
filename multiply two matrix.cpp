#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row1, colum1, row2, colum2;
    cout << "Enter 1st matrix ROW and COLUMN : ";
    cin >> row1 >> colum1;
    cout << "Enter 2nd matrix ROW and COLUMN : ";
    cin >> row2 >> colum2;

    int mat1[row1][colum1];
    int mat2[row2][colum2];
    int arrgun[row1][colum2];

    while(colum1 != row2)
    {
        cout << endl << "For multiply two matrix :" << endl << "The 1st matrix 'colunm' should be equal to the 2nd matrix 'row'" << endl;
        cout << " 1st matrix = A * B " << endl << " 2nd matrix = C * D " << endl;
        cout << "if B = C" << endl;
        cout << " then multiply is possible &" << endl;
        cout << " The output matrix size will be : ' A * D ' " << endl << endl;

        cout << "Enter 1st matrix ROW and COLUMN : ";
        cin >> row1 >> colum1;
        cout << "Enter 2nd matrix ROW and COLUMN : ";
        cin >> row2 >> colum2;

    }

    // User input of 1st matrix
    cout << "Enter 1st matrix elements " << "( " << row1 << " * " << colum1 << " )" << endl;
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < colum1; j++)
        {
            cin >> mat1[i][j];
        }
    }
    // User input of 2nd matrix
    cout << "Enter 2nd matrix elements " << "( " << row2 << " * " << colum2 << " )" << endl;
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < colum2; j++)
        {
            cin >> mat2[i][j];
        }
    }

    // Initialize all elements in zero in the resultent matrix

    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < colum2; j++)
        {
            arrgun[i][j] = 0;
        }
    }

    // Multiplication the two matrix
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < colum2; j++)
        {
            for(int k = 0; k < colum1; k++)
            {
                arrgun[i][j] = arrgun[i][j] + mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << endl << "Output Matrix :" << endl;
    // display the resultant matrix
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < colum2; j++)
        {
            cout << arrgun[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/* multiply krar conditions:
    * C = R ; 1st matrix er 'C' 2nd matrix er 'R'
    & the Output matrix : R * C ; 1st matrix er 'R' 2nd matrix er 'C'
*/

