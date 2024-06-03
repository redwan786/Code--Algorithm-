#include<bits/stdc++.h>
using namespace std;

#define INF 9999
#define NIL -1

int main()
{
    int mat1[5][5] = { {0, 3, 8, 4, -4},
        {INF, 0, INF, 1, 7},
        {INF, 4, 0, 5, 11},
        {2, 5, -5, 0, -2},
        {INF, INF, INF, 6, 0}
    };

    int mat2[5][5] = { {NIL, 1, 1, 2, 1},
        {NIL, NIL, NIL, 2, 2},
        {NIL, 3, NIL, 2, 2},
        {4, 1, 4, NIL, 1},
        {NIL, 4, NIL, 5, NIL}
    };

    for(int k = 0; k < 5; k++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                int temp = mat1[i][k] + mat1[k][j];
                if(mat1[i][k] != INF && mat1[k][j] != INF && temp < mat1[i][j]) {
                    mat1[i][j] = temp;
                }
            }
        }
    }

    cout << "New Matrix :" << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << mat1[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

