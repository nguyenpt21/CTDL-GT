#include<cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void random ( int a[] , int n )
{
   srand(time(0));

   for ( int i=0; i<n ; i++)
   {

      a[i]=rand() % 100 +1;

   }
}
void xuat( int a[], int n )
{
    for ( int i=0 ; i<n ; i++)
    {
        random (a,n);
        cout<< a[i]<< " ";
    }
}
void swap ( int x , int y )
{
    int temp = x;
        x = y;
        y = temp;
}
void Insertionsort ( int a[] , int n)
{
    for ( int i=0 ; i<n ; i++)
    {

        int x=a[i];

        int pos=i-1;

        while (pos>=0&&a[pos]>x)
        {
            a[pos+1]=x;
            pos --;
        }
        a[pos+1]=x;
    }
}
void Selectionsort (int a[], int n)
{
            for (int i = 0; i < n-1; i++)
            {
                    int min  = i;
                     for (int j = i; j < n; j++)
                     {
                          if (a[j] < a[min])   // Nếu sắp xếp giảm dần thì đổi thành: if (a[j] > a[index])
                               min  = j;
                     }
                     swap(a[i], a[min]);
             }
}

void BubbleSort(int a[], int n)
{
         for (int i = 0; i<n; i++)
         {
              int isSorted = 1;
              for (int j = n -1; j >= i+1; j--)
              {
                      if (a[j-1] > a[j])   // Nếu sắp xếp giảm dần thì đổi thành: if (a[j-1] < a[j])

                      {
                                isSorted = 0;
                                swap(a[j-1], a[j]);
                       }
              }
              if (isSorted)  break;
          }
}
void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if(a[i] > a[j]) //Thực hiện đổi chỗ phần tử nhỏ hơn với phần tử thứ i.
                swap(a[i], a[j]);
}

int main ()
{
    int n[]={100,500,1000,5000,10000};

    int M=5;// số lượng mảng khác nhau;

    for ( int i=0;i<5;i++)
    {
        int a[n[i]];
        {
            for ( int j=0; j<M ; j++)
            {
                random (a,n[i]);
                auto start=high_resolution_clock::now();// bắt đầu tính thời gian
                Insertionsort(a,n[i]);
                // Selectionsort (a,n[i]);
                // Interchangesort (a,n[i]);
                // Bubblesort (a,n[i]);
                auto stop=high_resolution_clock::now();// kết thúc tính thời gian
                auto duration= duration_cast<microseconds>(stop-start);// tính thời gian
                cout<<duration.count()<< endl;
            }
        }
    }
    return 0;
}
