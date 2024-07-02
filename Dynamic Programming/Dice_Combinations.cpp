#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int dp[maxn];
int n;
 
void Solve(){
    cin >>  n;
    dp[0] = 1;
    for(int i =1; i <= n; ++i){
        for(int j = 1; j <= 6; ++j){
            if(i >= j) dp[i] = (dp[i]+dp[i-j])%mod;
        }
    }
    cout << dp[n] << '\n';
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;//  cin >> T;
    while (T--) Solve();
}