#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e3+5;
 
int n;
char a[maxn][maxn];
int dp[maxn][maxn];
 
void Solve(){
   cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1;  i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if (a[i-1][j-1] == '*') dp[i][j] = 0;
            else dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    cout << dp[n][n];
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}