#include <bits/stdc++.h>
using namespace std;
int arr[100];
void merge(int arr[],int p,int q,int r)
{
    int l = p, r1 = q + 1, i = p;
    int b[20];
    while(l<=q and r1<=r)
    {
        if(arr[l]<arr[r1])
        {
            b[i] = arr[l];
            i++;
            l++;
        }
        else
        {
            b[i] = arr[r1];
            i++;
            r1++;
        }
    }
    while(l<=q)
    {
        b[i] = arr[l];
        l++;
        i++;
    }
    while(r1<=r)
    {
        b[i] = arr[r1];
        r1++;
        i++;
    }
    for (int i = p; i <= r;i++)
        arr[i] = b[i];
}
void mergesort(int arr[],int p, int r)
{
    int q;
    if(p<r)
    {
        q = (p + r) / 2;
        mergesort(arr, p,q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesort(arr, 0, n - 1);
    cout << "sorted elements:" << endl;
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
    return 0;
}