#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20; // Maximum board size
int x[MAX_N + 1]; // Array to store queen positions (1-indexed)
int countSolution = 0;

// Function to check if a queen can be placed in kth row and ith column
bool Place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

// Function to print the solution
void printSolution(int n)
{
    countSolution++;
    cout << "Solution " << countSolution << "->";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

// Recursive function to solve N-Queens problem
void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                printSolution(n);
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens (board size): ";
    cin >> n;

    if (n <= 0 || n > MAX_N)
    {
        cout << "Invalid board size. Please enter a number between 1 and " << MAX_N << "." << endl;
        return 1;
    }

    cout << "Solutions for " << n << "-Queens problem:" << endl;
    NQueens(1, n);

    if (countSolution == 0)
    {
        cout << "No solution for " << n << " Queens"  << endl;
    }

    return 0;
}


/*


Enter the number of queens (board size): 4
Solutions for 4-Queens problem:
Solution 1->2 4 1 3
Solution 2->3 1 4 2


Enter the number of queens (board size): 3
Solutions for 3-Queens problem:
No solution for 3 Queens



*/

