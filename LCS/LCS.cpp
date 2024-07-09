#include <bits/stdc++.h>
using namespace std;

string X, Y;

void LCS_Print(int c[][1000], string b[][1000], int m, int n)
{
    vector<string> RevSubSeq; // store the LCS reversely
    if (m == 0 || n == 0)
    {
        return;
    }

    if (b[m][n] == "\\")
    {
        RevSubSeq.push_back(string(1, X[m-1]));
        LCS_Print(c, b, m - 1, n - 1);

    }
    else if (b[m][n] == "|")
    {
        LCS_Print(c, b, m - 1, n);
    }
    else
    {
        LCS_Print(c, b, m, n - 1);
    }



    for(int i = RevSubSeq.size()-1; i >= 0; i--)
    {
        cout << RevSubSeq[i];
    }

}


void LCS_Length()
{
    int m = X.length();
    int n = Y.length();

    int c[m+1][1000]; // length matrix
    string b[m+1][1000]; // direction matrix

    // Initialize first column and first row
    for(int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
        b[i][0] = "x"; // Initialize the first column of 'b' to "x"
    }

    for(int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
        b[0][j] = "x"; // Initialize the first row of 'b' to "x"
    }

    // LCS algorithm to fill the matrixes
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = "\\";
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = "|";
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = "-";
            }
        }
    }

    // displaying matrix c
    cout << endl << "Matrix c:" << endl;
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    // displaying matrix b
    cout << endl << "Matrix b:" << endl;
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "LCS :";
    LCS_Print(c, b, m, n);
    cout << " :" << c[m][n] << endl;



}

int main()
{
    cout << "Enter 1st string: ";
    cin >> X;

    cout << "Enter 2nd string: ";
    cin >> Y;

    LCS_Length();
}
