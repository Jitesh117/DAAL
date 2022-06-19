#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of items in the knapsack";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter values of weights and profits in pairs";
    for (int  i = 0; i < n; i++)
    {
        cin >> wt[i] >>val[i];
    }
    int w;
    cout << "Enter max capacity:";
    cin >> w;
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            if (i == 0 or j == 0)
                dp[i][j] = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= w;j++)
        {
            if (wt[i] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << "Max profit:" << dp[n][w];
    return 0;
}