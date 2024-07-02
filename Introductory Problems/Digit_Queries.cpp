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
    int k;
    cin >> k;
    int dig = 1, pow10  = 1;
    while(1){
        int x = 9LL*pow10*dig;
        if(k > x) k-= x, dig++, pow10*=10;
        else break;
    }
    k--;
    int res = pow10+ k/dig;
    k%=dig;
    cout << to_string(res)[k] << '\n';
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; cin >> T;
    while(T--) Solve();
}