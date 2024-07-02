#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
void Solve() {
    int n, m;
    cin >> n >> m;
    cout << ((n+m)%3 == 0 && min(n,m)*2>=max(n,m)? "YES\n" : "NO\n");
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; cin >> T;
    while(T--) Solve();
}