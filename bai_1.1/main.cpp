#include <iostream>

using namespace std;
void Xuat(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}
void Xoa(int a[], int &n, int k)
{
    for(int i=k;i<n-1;i++)
        a[i]=a[i+1];
    --n;
}
void LietKeNhungPhanTuLonNhat(int a[], int n)
{
    int max = a[0], index;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=max)
        {
            max=a[i];
            index = i;
        }
    }
    cout << "Nhung phan tu lon nhat co gia tri la " << a[index] << " va co cac chi so la ";
    for(int i=0;i<n;i++)
    {
        if(a[i]==max)
        {
            cout << i;
            if(i!=index) cout << ", ";
        }

    }
    cout << endl;
}
void LietKeNhungPhanTuNhoNhat(int a[], int n)
{
    int min = a[0], index ;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=min)
        {
             min = a[i];
             index = i;
        }
    }
    cout << "Nhung phan tu nho nhat co gia tri la " << min << " va co cac chi so la ";
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[index])
        {
            cout << i;
            if(i!=index) cout << ", ";
        }
    }
    cout << endl;
}
int DemPhanTuCoGiaTriAm(int a[], int n)
{
    int dem = 0;
    for(int i=0;i<n;i++)
        if(a[i]<0) dem++;
    return dem;
}
void GiaTriAmLonNhat(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]<0) break;
    if(i==n) cout << "Mang khong co so am." << endl;
    else
    {
        int max=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<0 && a[j] > max) max = a[j];
        }
        cout << "Gia tri am lon nhat la: " << max << endl;
    }
}
void GiaTriDuongNhoNhat(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]>0) break;
    if(i==n) cout << "Mang khong co so duong." << endl;
    else
    {
        int min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>0 && a[i]<min) min = a[j];
        }
        cout << "Gia tri duong nho nhat la: " << min << endl;
    }
}
void TimPhanTu(int a[], int n, int x)
{
    int ok=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            ok=true;
            cout << "Phan tu " << x << " co trong mang" << endl;
            break;
        }
    }
    if(ok==false) cout << "Phan tu " << x << " khong co trong mang" << endl;
}
void DemSoPhanTuCoGiaTriX(int a[], int n, int x)
{
    int dem=0;
    for(int i=0;i<n;i++)
        if(a[i]==x) dem++;
    cout << "So phan tu co gia tri bang " << x << " la: " << dem << endl;
}
int main()
{
    int n; cout << "So phan tu cua mang: "; cin >> n;
    int a[n];
    cout << "Nhap mang: ";
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "Mang vua nhap la: "; Xuat(a, n);
    LietKeNhungPhanTuLonNhat(a, n);
    LietKeNhungPhanTuNhoNhat(a, n);
    cout << "So phan tu co gia tri am trong mang la: " << DemPhanTuCoGiaTriAm(a, n) << endl;
    GiaTriAmLonNhat(a, n);
    GiaTriDuongNhoNhat(a, n);
    int k;
    cout << "Phan tu can tim: ";cin.ignore(); cin >> k;
    TimPhanTu(a, n, k);
    int x;
    cout << "Phan tu co gia tri: "; cin >> x;
    DemSoPhanTuCoGiaTriX(a, n, x);
    int m;
    cout << "Phan tu can xoa co chi so: "; cin >> m;
    Xoa(a, n, m);
    cout << "Mang sau khi xoa phan tu co chi so " << m << " : "; Xuat(a, n);
    return 0;
}
