#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int p,int q,int r)
{
    int left = p;
    int right = q + 1;
    int i = p;
    int b[20];
    while(left<=q and right<=r)
    {
        if(arr[left]<arr[right])
        {
            b[i] = arr[left];
            left++;
            i++;
        }
        else
        {
            b[i] = arr[right];
            right++;
            i++;
        }
    }
    while(left<=q)
    {
        b[i] = arr[left];
        left++;
        i++;
    }
    while(right<=r)
    {
        b[i++] = arr[right++];
    }
    for (int i = p; i <= r; i++)
        arr[i] = b[i];
}
void mergesort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main()
{
    int arr[10];
    cout << "Enter size of the array:";
    int n;
    cin >> n;
    cout << "Enter elements of the array:";
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    mergesort(arr, 0, n - 1);
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
    return 0;
}