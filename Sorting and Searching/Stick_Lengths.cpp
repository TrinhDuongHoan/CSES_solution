#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
int n;
int a[maxn];
 
void Solve() {
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; ++i){
        ans += abs(a[i]-a[(n+1)/2]);
    }
    cout << ans ;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}