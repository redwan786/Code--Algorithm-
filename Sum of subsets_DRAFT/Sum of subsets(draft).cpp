#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;  // Maximum number of elements allowed

// Global variables
int n, m;  // n: number of elements, m: target sum
int w[MAX_N + 1];  // Weight array (1-indexed) to store input elements
int x[MAX_N + 1];  // Array to keep track of current subset being considered (1 if included, 0 if not)

// Function to print the subset
void printSubset()
{
    // Print all elements
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " ";  // Print weight of each element
    }
    cout << endl;

    // Print whether each element is in the current subset (1) or not (0)
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";  // Print 1 if included in subset, 0 if not
    }
    cout << endl << endl;
}

// Recursive function to find subsets
void SumOfSub(int k, int currentSum, int remainingSum)
{
    // If current sum equals target, we found a valid subset
    if (currentSum == m)
    {
        printSubset();  // Print the found subset
        return;  // Return from this branch
    }

    // Base cases to stop recursion
    if (k > n || currentSum > m || currentSum + remainingSum < m)
    {
        return;  // Stop if we've gone past n, exceeded m, or can't reach m
    }

    // Include w[k] in the subset
    x[k] = 1;  // Mark w[k] as included in current subset
    SumOfSub(k + 1, currentSum + w[k], remainingSum - w[k]);  // Recurse with w[k] included
    x[k] = 0;  // Unmark w[k] (backtrack)

    // Exclude w[k] from the subset
    SumOfSub(k + 1, currentSum, remainingSum - w[k]);  // Recurse without w[k]
}

int main()
{
    cout << "Enter Element Number: ";
    cin >> n;  // Input number of elements
    cout << "Enter Elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];  // Input each element
    }

    // Sort the array in ascending order
    sort(w + 1, w + n + 1);

    // Print sorted array
    cout << "Element(sorted): ";
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;

    cout << "Enter Target Sum : ";
    cin >> m;  // Input target sum
    cout << endl;

    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        totalSum += w[i];  // Calculate total sum of all elements
        x[i] = 0;  // Initialize all elements as not included in subset
    }

    SumOfSub(1, 0, totalSum);  // Start recursion with initial values

    return 0;  // End of program
}
