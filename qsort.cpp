#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int p,int r)
{
    int left = p - 1;
    int right = r + 1;
    int k = arr[p];
    while(1)
    {
        do
        {
            right--;
        } while (arr[right]>k);
        do
        {
            left++;
        } while (arr[left]<k);
        if(left<right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        else
            return right;
        }
}
void quick(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = partition(arr, p, r);
        quick(arr, p, q);
        quick(arr, q + 1, r);
    }
}
int main()
{
    int arr[10], n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    quick(arr, 0, n - 1);
    for (int i = 0; i < n;i++)
        cout << arr[i] << " ";
    return 0;
}