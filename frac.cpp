#include<bits/stdc++.h>
using namespace std;
static bool comp()
int main()
{
    int arr[10][2];
    int n;
    cout << "Enter number of items:";
    cin >> n;
    cout << "Enter the weights and profits in pairs:";
    for (int i = 0; i < n;i++)
        cin >> arr[i][0] >> arr[i][1];
    int w;
    cout << "Enter max capacity:";
    cin >> w;
    bool used[n];
    for (int i = 0; i < n;i++)
        used[i] = false;
    int maxi=0;
    int curw = w;
    while(curw>=0)
    {
        maxi = -1;
        for (int i = 0; i < n;i++)
        {
            if((used[i] == false and maxi == -1) or((float)arr[i][1]/(flaot)))
        }
    }
}