#include <bits/stdc++.h>
using namespace std;
struct job
{
    char id;
    int dead;
    int profit;
};
bool comparison(job a, job b)
{
    return a.profit > b.profit;
}
void printjob(job arr[], int n)
{
    sort(arr, arr + n, comparison);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n;i++)
        slot[i] = false;
    for (int i = 0; i < n;i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0;j--)
        {
            if(slot[j] == false)
            {
                slot[j] = false;
                result[j] = i;
            }
        }
    }
    for (int i = 0; i < n;i++)
    if(slot[i])
        cout << arr[result[i]].id << " ";
}
