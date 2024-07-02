#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e5+6;
const ll mod = 1e9+7;
 
ll a[maxn], dp[maxn][105];
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    ll n, m , ans = 0LL;
    cin >> n >> m ;
    for(int i = 1; i <= n ; ++i) cin >> a[i];
    if(a[1] > 0LL) dp[1][a[1]] = 1LL;
    else for(int i =1; i <= m; ++i) dp[1][i] = 1;
    for(int i =1; i <= n; ++i){
        if(a[i] == 0LL){
            for(int j = 1; j <= m; ++j){
                if(j - 1 >= 1LL)
                    dp[i][j] = (dp[i][j]+ dp[i-1][j-1])%mod;
                dp[i][j] = (dp[i][j]+ dp[i-1][j])%mod;
                if(j+1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
        else{
            if(a[i]-1 >= 1LL)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1]) % mod;
            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]])%mod;
            if(a[i]+1 <= m)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+1])%mod;
        }
    }
//    for(int i =1;  i <= m; ++i) cout << dp[n][i] << ' ';
    for(int i = 1; i <= m; ++i){
        ans += dp[n][i];
    }
    cout << ans%mod;
    return 0;
}