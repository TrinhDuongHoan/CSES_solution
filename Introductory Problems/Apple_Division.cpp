#include <bits/stdc++.h>
using namespace std;
#define int long long
int X[2000005],Y[2000005];

void calcsubarray(int a[], int x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        int s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        x[i] = s;
    }
}
int solveSubsetSum(int a[], int n, int S)
{
    calcsubarray(a, X, n/2, 0);
    calcsubarray(a, Y, n-n/2, n/2);

    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);
    sort(Y, Y+size_Y);
    int max = 0;
    for (int i=0; i<size_X; i++)
    {
        if (X[i] <= S)
        {
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
            if (p == size_Y || Y[p] != (S-X[i]))
                p--;
            if ((Y[p]+X[i]) > max)
                max = Y[p]+X[i];
        }
    }
    return max;
}

signed main()
{
    int s = 0;
    int n; cin >> n ;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i],s+=a[i];
    int mid = s/2;
    cout << s - 2*solveSubsetSum(a,n,mid) ;
}