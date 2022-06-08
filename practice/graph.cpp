#include <bits/stdc++.h>
using namespace std;
#define node 6
int graph[node][node] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 0}};

void graphcolor()
{
    int color[node];
    bool colorused[node];
    for (int i = 0; i < node; i++)
    {
        color[i] = -1;
        colorused[i] = false;
    }
    color[0] = 0;
    for (int u = 1; u < node;u++)
    {
        for (int v = 0; v < node;v++)
            if(graph[u][v])
                if(color[v]!=-1)
                    colorused[color[v]] = true;
        int col;
        for (col = 0; col < node;col++)
            if(colorused[col] == false)
                break;
        color[u] = col;
        for (int v = 0; v < node;v++)
            if(graph[u][v])
                if(color[v]!=-1)
                    colorused[color[v]] = false;
    }
        for (int u = 0; u < node; u++)
            cout << "Node: " << u << " assigned with color: " << color[u] << endl;
}
int main()
{
    graphcolor();
    return 0;
}