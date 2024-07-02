#include <bits/stdc++.h>
#define file "TASK"
#define int long long
#define read(file) freopen(file ".INP", "r", stdin)
#define write(file) freopen(file ".OUT", "w", stdout)
#define all(a) a.begin(),a.end()
#define sz(a) (int) a.size()
#define el '\n'
using namespace std;
 
void debug_out() {cout << endl;}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debugAr(a,l,r) for(int i = l ; i <= r; ++i) debug(i,a[i]);
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
const int inf = LLONG_MAX;
const int Robert = 212004;
 
int dp[5005][5005];
 
 
void Solve(){
    string s1, s2; cin >> s1 >> s2;
    int n = sz(s1), m = sz(s2);
    for(int i = 0 ; i <= n; ++i) for(int j = 0 ; j <= m ; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0; j <= m ; ++j){
            if(i != 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j != 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(i != 0 && j != 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
        }
    }
    cout << dp[n][m] ;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    if(fopen(file ".INP", "r")) read(file), write(file);
    int T = 1;// cin >> T;
    while(T--) Solve();
}