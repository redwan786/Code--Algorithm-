#include<bits/stdc++.h>
using namespace std;
#define I 10000
#define N -1


void floydWarshall(int D[][5], int Pi[][5])
{
    // Floyd-Warshall algorithm
    // Loop k for the D0, D1......
    for(int k = 0; k < 5; k++)
    {
        // Loop i for Row
        for(int i = 0; i < 5; i++)
        {
            // Loop j for Column
            for(int j = 0; j < 5; j++)
            {
                int temp = D[i][k] + D[k][j];
                // cout << "D[" << i << "][" << k << "] = " << D[i][k] << " && " << "D[" << k << "][" << j << "] = " << D[k][j] << endl;
                // cout << k << "--> (" << i << " " << j << "), Temp: " << temp << endl << endl;
                if(temp < D[i][j])
                {
                    D[i][j] = temp;
                    Pi[i][j] = Pi[k][j];
                }
            }
        }
    }

}




int main()
{
    int D[5][5] =
    {
        {0, 3, 8, I, -4},
        {I, 0, I, 1, 7},
        {I, 4, 0, I, I},
        {2, I, -5, 0, I},
        {I, I, I, 6, 0}
    };

    int Pi[5][5] =
    {
        {N, 1, 1, N, 1},
        {N, N, N, 2, 2},
        {N, 3, N, N, N},
        {4, N, 4, N, N},
        {N, N, N, 5, N}
    };

    cout << "Initial D matrix:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (D[i][j] == I)
            {
                cout << "+I  ";
            }
            else if (D[i][j] >= 0)
            {
                cout << "+" << D[i][j] << "  ";
            }
            else
            {
                cout << D[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "Initial Pi matrix:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Pi[i][j] == N)
            {
                cout << "N  ";
            }
            else
            {
                cout << Pi[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    floydWarshall(D, Pi);

    cout << "Final D matrix:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (D[i][j] == I)
            {
                cout << "+I  ";
            }
            else if (D[i][j] >= 0)
            {
                cout << "+" << D[i][j] << "  ";
            }
            else
            {
                cout << D[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "Final Pi matrix:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Pi[i][j] == N)
            {
                cout << "N  ";
            }
            else
            {
                cout << Pi[i][j] << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}
