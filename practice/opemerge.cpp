#include <bits/stdc++.h>
using namespace std;

int minComputation(int n,int files[])
{
    priority_queue<int, vector<int>, greater < int >> pq;
    for (int i = 0; i < n;i++)
        pq.push(files[i]);
    int count = 0;
    while(pq.size()>1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();      
        pq.pop();
        count += first + second;
        pq.push(first + second);
    }
    return count;
}
// Driver code
int main()
{

    int n = 6;

    int files[] = {2, 3, 4, 5, 6, 7};

    cout << "Minimum Computations = "
         << minComputation(n, files);

    return 0;
}
