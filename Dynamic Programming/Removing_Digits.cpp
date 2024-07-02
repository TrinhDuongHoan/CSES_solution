#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int maxDigit(int n){
    int res = 0;
    while(n){
        res = max(res, n%10);
        n/=10;
    }
    return res;
}
    
void Solve(){
    int n; cin >> n;
    int cnt  = 0;
    while(n){
        cnt++;
        n-=maxDigit(n);
    }
    cout << cnt << '\n';
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) Solve();
}