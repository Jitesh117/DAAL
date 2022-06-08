#include <bits/stdc++.h>
using namespace std;
#define node 6
#define inf 999
int costmatrix[node][node] =
    {
        {0, 3, 7, inf, 20, 6},
        {inf, 0, inf, inf, inf, 2},
        {inf, inf, 0, 8, 6, inf},
        {inf, inf, inf, 0, 4, inf},
        {inf, inf, inf, inf, 0, inf},
        {inf, inf, inf, 3, inf, 0}
    };
void solve()
{
    int cost[node][node];
    int n = node;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = costmatrix[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];

    cout << "The matrix for shortest path:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << cost[i][j];
        }
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}