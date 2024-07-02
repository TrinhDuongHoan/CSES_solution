#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int a[maxn],dp[maxn];
int n,x;
 
void Solve(){
    cin >> n >> x;
    for(int i =1;i <= x; ++i) dp[i] = inf;
    for(int i =1; i <= n; ++i) cin >> a[i];
    for(int i =1; i <= x;++i){
        for(int j = 1; j <= n; ++j){
            if(i >= a[j]) dp[i] = min(dp[i], dp[i-a[j]]+1);
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]);
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}