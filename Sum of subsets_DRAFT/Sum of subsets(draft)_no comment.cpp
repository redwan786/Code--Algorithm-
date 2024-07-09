#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;

int n, m;
int w[MAX_N + 1];
int x[MAX_N + 1];

void printSubset()
{
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl << endl;
}

void SumOfSub(int k, int currentSum, int remainingSum)
{
    if (currentSum == m)
    {
        printSubset();
        return;
    }

    if (k > n || currentSum > m || currentSum + remainingSum < m)
    {
        return;
    }

    x[k] = 1;
    SumOfSub(k + 1, currentSum + w[k], remainingSum - w[k]);
    x[k] = 0;

    SumOfSub(k + 1, currentSum, remainingSum - w[k]);
}

int main()
{
    cout << "Enter Element Number: ";
    cin >> n;
    cout << "Enter Elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    sort(w + 1, w + n + 1);

    cout << "Element(sorted): ";
    for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;

    cout << "Enter Target Sum : ";
    cin >> m;
    cout << endl;

    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        totalSum += w[i];
        x[i] = 0;
    }

    SumOfSub(1, 0, totalSum);

    return 0;
}
