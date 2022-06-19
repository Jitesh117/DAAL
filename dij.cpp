#include <bits/stdc++.h>
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum = INT_MAX;
    int ind;
    for (int i = 0; i < 6;i++)
    {
        if(distance[i]<minimum and Tset[i] == false)
            {
                minimum = distance[i];
                ind = i;
            }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6], int src) // adjacency matrix
{
    int distance[6];
    bool tset[6];
    distance[src] = 0;
    for (int i = 1; i < 6;i++)
        distance[i] = INT_MAX, tset[i] = false;

    int n = 6;
    for (int i = 0; i < n;i++)
    {
        int m = miniDist(distance, tset);
        tset[m] = true;
        for (int k = 0; k < n;k++)
        {
            if(graph[m][k] and tset[k]==false and distance[m]!=INT_MAX and distance[k]>distance[m]+graph[m][k])
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
    DijkstraAlgo(graph, 0);
    return 0;
}