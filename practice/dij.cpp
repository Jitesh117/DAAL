#include<bits/stdc++.h>
using namespace std;
int mindist(int distance[], bool tset[])
{
    int minimum = INT_MAX;
    int ind;
    for (int i = 0; i < 6;i++)
    if(distance[i]<minimum and tset[i] == false)
    {
        minimum = distance[i];
        ind = i;
    }
    return ind;
}
void dij(int graph[6][6],int src)
{
    int distance[6];
    bool tset[6];
    for (int i = 0; i < 6;i++)
        distance[i] = INT_MAX, tset[i] = false;

    distance[src] = 0;
    for (int i = 0; i < 6;i++)
    {
        int m = mindist(distance, tset);
        tset[m] = true;
        for (int k = 0; k < 6;k++)
            {
                if(!tset[k] and graph[m][k] and distance[m]!=INT_MAX and distance[m]+graph[m][k]<distance[k])
                    distance[k] = distance[m] + graph[m][k];
            }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}
int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    dij(graph, 0);
    return 0;
}