#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;

int binpow(int a, int b){
    int res = 1;
    while(b){   
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int total_sum(int l, int r){
    return ((((l + r)%mod) * ((r - l + 1) %mod)) % mod * binpow(2,mod-2) % mod)%mod;
}

void Solve(){
    int n; cin >> n;
    int ans = 0, at = 1;
    while(at <= n){
        int add = n / at;
        int nxt = n / add;
        ans = (ans + add * total_sum(at,nxt)) % mod;
        ans %= mod;
        at = nxt + 1;
    }
    cout << ans % mod << el;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    if(fopen("ROBERT.INP","r")){
        freopen("ROBERT.INP","r",stdin);
        freopen("ROBERT.OUT","w",stdout);
    }
    int nTest = 1; //cin >> nTest;
    while(nTest--) Solve();
}