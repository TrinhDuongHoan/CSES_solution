/*
    Author : Trinh Duong Hoan
    K18 KHDL IUH
*/
#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) (int) a.size()
#define el '\n'
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
const int inf = LLONG_MAX;
 
void debug_out() {cout << endl;}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
 
void setIO(string name = "")
{
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); 
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
 
// ---------------- Code place -------------------------\
 
int n;
int dp[maxn];
 
int binpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
void Robert(){
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum % 2 ){
        cout << 0;
        return ;
    }
    int half_sum = sum/2;
 
    dp[0] = 1;
    for(int i = 1 ; i <= n; ++i){
        for(int j = half_sum ; j >= i; --j){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    cout << dp[half_sum] * binpow(2LL,mod-2) % mod << el;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    // setIO("hehehehe");
    int T = 1;
    // cin >> T;
    while (T--) 
        Robert();
}