#include<bits/stdc++.h>
using namespace std;
void solve(int i, vector<int> v, int sum,vector<int> temp, vector<vector<int>> &result)
{
    if(sum == 0)
    {
        for (int i = 0; i < temp.size();i++)
            cout << temp[i] << " ";
        cout << endl;
        return;
    }
    if(v[i]<=sum)
    {
        temp.push_back(v[i]);
        solve(i + 1, v, sum - v[i], temp, result);
        temp.pop_back();
        solve(i + 1, v, sum, temp, result);
    }
    // solve(i + 1, v, sum, temp, result);
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array:";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n;i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int sum;
    cout << "Enter the sum:";
    cin >> sum;
    vector<vector<int>> result;
    vector<int> temp;
    solve(0, v, sum,temp,result);
    // for (int i = 0; i < result.size();i++)
    //     {
    //         for (int j = 0; j < result[i].size();j++)
    //             cout << result[i][j] << " ";
    //         cout << endl;
    //     }
        return 0;
}