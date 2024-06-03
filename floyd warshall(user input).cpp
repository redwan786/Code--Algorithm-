#include <bits/stdc++.h>
using namespace std;

//#define I 10000
#define N -1

void floydWarshall(int D[][100], int Pi[][100], int size)
{
    // Floyd-Warshall algorithm
    // k loop for D0, D1, D2.....
    for (int k = 0; k < size; k++)
    {
        // i loop for row
        for (int i = 0; i < size; i++)
        {
            // j loop for colunm
            for (int j = 0; j < size; j++)
            {
                int temp = D[i][k] + D[k][j];
                // cout << "D[" << i << "][" << k << "] = " << D[i][k] << " && " << "D[" << k << "][" << j << "] = " << D[k][j] << endl;
                // cout << k << "--> (" << i << " " << j << "), Temp: " << temp << endl << endl;
                if (temp < D[i][j])
                {
                    D[i][j] = temp;
                    Pi[i][j] = Pi[k][j];
                }
            }
        }
        // cout << endl << endl;
    }
}

void printPath(int Pi[][100], int i, int j)
{
    if (i == j)
    {
        //cout << "i:" << i << " j:" << j  << "    ";
        cout << i;
    }
    else if (Pi[i][j] == N)
    {
        cout << "No path from " << i << " to " << j;
    }
    else
    {
        //cout << "i:" << i << " j:" << j  << " ";
        //cout << "Pi[" << i << "][" << j << "] :" << Pi[i][j] << " " ;
        printPath(Pi, i, Pi[i][j]);
        cout << "->" << j;
    }

}


int main()
{
    freopen("user input.txt", "r", stdin);
    int size;
    cout << "Enter Matrix Size : ";
    cin >> size;
    int D[100][100];
    int Pi[100][100];


    cout << "Enter the matrix D (" << size << "x" << size << ") :" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> D[i][j];
            if (D[i][j] == 10000)
            {
                D[i][j] = I;
            }
        }
    }
    cout << endl;
    cout << "Enter the matrix Pi (" << size << "x" << size << ") :" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> Pi[i][j];
            if (Pi[i][j] == -1)
            {
                Pi[i][j] = N;
            }
        }
    }
    cout << endl;

    cout << "Initial D matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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

    floydWarshall(D, Pi, size);

    cout << "Final D matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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

    // for printing all path
    cout << "All paths:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                cout << "Path (" << i << "->" << j << "): ";
                printPath(Pi, i, j);
                cout << ", Cost=" << D[i][j] << endl;
                cout << endl;
            }
        }

    }



    // for a specific path
    cout << "A specific Path (" << 1 << "->" << 2 << "): ";
    printPath(Pi, 1, 2);
    cout << ", Cost=" << D[1][2] << endl;



    return 0;
}

/*

Enter Matrix Size : Enter the matrix D (5x5) :

Enter the matrix Pi (5x5) :

Initial D matrix:
+0  +3  +8  +I  -4
+I  +0  +I  +1  +7
+I  +4  +0  +I  +I
+2  +I  -5  +0  +I
+I  +I  +I  +6  +0

Initial Pi matrix:
N  1  1  N  1
N  N  N  2  2
N  3  N  N  N
4  N  4  N  N
N  N  N  5  N

Final D matrix:
+0  +1  -3  +2  -4
+3  +0  -4  +1  -1
+7  +4  +0  +5  +3
+2  -1  -5  +0  -2
+8  +5  +1  +6  +0

Final Pi matrix:
N  3  4  5  1
4  N  4  2  1
4  3  N  2  1
4  3  4  N  1
4  3  4  5  N

All paths:
Path (0->1): 0->5->3->1, Cost=1
Path (0->2): 0->5->3->1->4->2, Cost=-3
Path (0->3): 0->5->3, Cost=2
Path (0->4): 0->5->3->1->4, Cost=-4
Path (1->0): 1->4->0, Cost=3
Path (1->2): 1->4->2, Cost=-4
Path (1->3): 1->4->2->3, Cost=1
Path (1->4): 1->4, Cost=-1
Path (2->0): 2->3->1->4->0, Cost=7
Path (2->1): 2->3->1, Cost=4
Path (2->3): 2->3, Cost=5
Path (2->4): 2->3->1->4, Cost=3
Path (3->0): 3->1->4->0, Cost=2
Path (3->1): 3->1, Cost=-1
Path (3->2): 3->1->4->2, Cost=-5
Path (3->4): 3->1->4, Cost=-2
Path (4->0): 4->0, Cost=8
Path (4->1): 4->0->5->3->1, Cost=5
Path (4->2): 4->2, Cost=1
Path (4->3): 4->0->5->3, Cost=6

*/
