#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
 
int n, x, a[maxn], check[maxn];
void Solve(){
   cin >> n >> x;
   for(int i = 1; i <= n; ++i) cin >> a[i];
   sort(a+1,a+1+n);
   int l = 1, r = n, cnt = 0;
   while (l < r){
        if (a[l]+a[r] > x) r--;
        else{
            cnt++;
            check[l] = check[r] = 1;
            l++;
            r--;
        }
   }
   for(int i = 1; i <= n; ++i) if (!check[i]) cnt++;
   cout << cnt  ;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}