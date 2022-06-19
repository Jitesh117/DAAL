#include <bits/stdc++.h>
using namespace std;
#define node 5
#define inf 999
int costmatrix[node][node] =
    {
        {0, 1, -3, 2, -4},
        {3, 0, -4, 1, -1},
        {7, 4, 0, 5, 3},
        {2, -1, -5, 0, -2},
        {8, 5, 1, 6, 0}};
void solve()
{
    int cost[node][node];
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            cost[i][j] = costmatrix[i][j];
    for (int k = 0; k < node; k++)
        for (int i = 0; i < node; i++)
            for (int j = 0; j < node; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
    cout << "The shortest path matrix is:" << endl;
    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            cout << setw(5) << cost[i][j];
        }
        cout << endl;
    }
}
int main()
{
    // #ifndef ONLINE_JUDGE

    //     freopen("input.txt", "r", stdin);

    //     freopen("output.txt", "w", stdout);

    // #endif // ONLINE_JUDGE
    solve();

    return 0;
}