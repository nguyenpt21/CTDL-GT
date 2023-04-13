#include <bits\stdc++.h>

using namespace std;
void Merge(int a[], int l, int m, int r)
{
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i=0, j=0;
    while(i<x.size() && j<y.size())
    {
        if(x[i]>=y[j])
            a[l++]=x[i++];
        else
            a[l++]=y[j++];
    }
    while(i<x.size())
    {
        a[l++]=x[i++];
    }
    while(j<y.size())
        a[l++]=y[j++];
}
void MergeSort(int a[], int l, int r)
{
    if(l>=r) return;
    int m=(l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    Merge(a, l, m, r);
}
int H_index(int a[], int n)
{
    MergeSort(a, 0, n-1);
    int i=0, cnt=0;
    if(a[i]==0) return 0;
    while(i<n && a[i]>=cnt+1)
    {
        cnt++;
        i++;
    }
    return cnt;
}

int main()
{
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << H_index(a, n); cout << endl;
    return 0;
}
