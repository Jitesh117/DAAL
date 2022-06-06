#include <bits/stdc++.h>
using namespace std;
void quicksort(int[], int, int);
int partition(int[], int, int);
int main()
{
    int x[20], n;
    cout << "Enter the number of elements:";
    cin >> n;
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    quicksort(x, 0, n - 1);
    cout << "The sorted array is:";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    return 0;
}
void quicksort(int a[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q);
        quicksort(a, q + 1, r);
    }
}
int partition(int a[],int p,int r)
{
    int k, i, j, temp;
    k = a[p];
    i = p - 1;
    j = r + 1;
    while(1)
    {
        do{
            j--;
        } while (a[j] > k);
        do
        {
            i++;
        }while(a[i]<k);
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            return j;
        }
    }
}
