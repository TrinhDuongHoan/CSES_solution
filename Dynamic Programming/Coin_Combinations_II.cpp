#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int n,  S;
int a[maxn], pre[maxn], dp[maxn];
 
void Solve(){
   cin >> n >> S;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   pre[0] = 1;
   for(int i =1; i <= n; ++i){
        for(int  s = 0 ; s <= S; ++s){
            dp[s] = pre[s];
            if(s-a[i] >= 0) dp[s] = (dp[s]+dp[s-a[i]])%mod;
        }
        for(int j = 0 ; j <= S; ++j) pre[j] = dp[j]; 
   }
   cout << dp[S];
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}