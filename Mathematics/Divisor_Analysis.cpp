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
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void Solve(){
    int n; cin >> n;
    int sum = 1, prod = 1, cnt = 1, d = 1;
    for(int i = 1; i <= n ; ++i){
        int x, k; cin >> x >> k;
        cnt = cnt * (k + 1) % mod;

        sum = (sum % mod * (binpow(x, k + 1) - 1 + mod) % mod * binpow(x - 1, mod - 2) % mod) % mod;

        prod = (binpow(prod, k + 1) % mod * binpow(binpow(x,k * (k + 1) / 2) % mod,d) % mod)%mod;

        d = d * (k + 1) % (mod - 1);
    }
    cout << cnt << " " << sum << " " << prod << el;
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