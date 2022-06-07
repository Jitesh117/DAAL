#include <bits/stdc++.h>
using namespace std;
#define node 7
#define inf 999
int costmatrix[node][node] =
    {
        {0, 3, 6, inf, inf, inf, inf},
        {3, 0, 2, 1, inf, inf, inf},
        {6, 2, 0, 1, 4, 2, inf},
        {inf, 1, 1, 0, 2, inf, 4},
        {inf, inf, 4, 2, 0, 2, 1},
        {inf, inf, 2, inf, 2, 0, 1},
        {inf, inf, inf, 4, 1, 1, 0}};
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
            cout << setw(3) << cost[i][j];
        }
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}