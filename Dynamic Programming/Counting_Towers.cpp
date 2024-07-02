#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e6+5;
const ll mod = 1e9+7;
 
ll dp[maxn][3];
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i = 2; i < maxn; ++i){
        dp[i][1] = (2*dp[i-1][1]%mod + dp[i-1][2]%mod)%mod;
        dp[i][2] = (dp[i-1][1]%mod + 4*dp[i-1][2]%mod)%mod;
    }
    int test;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        cout << (dp[n][1]%mod+dp[n][2]%mod)%mod << '\n';
    }
    return 0;
}