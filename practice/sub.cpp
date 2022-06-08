#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5, m = 6;
    vector<pair<int, int>> adj[n];
    int a, b, wt;
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    int key[n], parent[n];
    bool mstset[n];
    for (int i = 0; i < n;i++)
        key[n] = INT_MAX, mstset[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count=0;count<n-1;count++)
    {
        int mini = INT_MAX, u;
        for (int v = 0; v < n;v++)
            if(key[v]<mini and mstset[v] == false)
                mini = key[v], u = v;
        mstset[u] = true;
        for (auto it:adj[u])
        {
            int weight = it.second;
            int v = it.first;
            if(key[v]>weight and mstset[v] == false)
                parent[v] = u, key[v] = weight;
                
        }
    }
}