#include<bits/stdc++.h>
using namespace std;
#define node 6
int graph[node][node] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 0}};
void coloring()
{
    int color[node];
    bool colorused[node];
    for (int i = 0; i < node;i++)
        color[i] = -1, colorused[i] = false;
    color[0] = 0;
    for (int i = 1; i < node;i++)
    {
        for (int j = 0; j < node;j++)
        {
            if(color[j]!=-1)
                colorused[j] = true;
        }
        int col;
        for (col = 0; col < node;col++)
            if(colorused[col]==false)
                break;
        color[i] = col;
        for (int j = 0; j < node;j++)
        if(graph[i][j])
            if(color[j]!=-1)
                colorused[j] = false;
    }
    for (int u = 0; u < node; u++)
        cout << "Node: " << u << ", Assigned with Color: " << color[u] << endl;
}
int main()
{
    coloring();
    return 0;
}