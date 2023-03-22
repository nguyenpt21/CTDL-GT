#include <iostream>

using namespace std;
bool check(long long mid, int a[], int n, int k) {
    long long sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] > mid) {
            cnt++;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return cnt <= k;
}

long long Hoiky(int a[], int n, int k) {
    long long low = INT_MIN, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, (long long) a[i]);
        high += a[i];
    }
    long long res = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid, a, n, k)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << Hoiky(a, n, k);
    return 0;
}
