#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;
 
int cal(int n, int k){
    if(n == 1) return 1;
    if(k <= (n + 1) / 2) {
        if(2 * k > n ) return 2 * k % n;
        else return 2 * k;
    }
    int res = cal(n / 2, k - (n + 1) / 2);
    if(n % 2 == 0) return 2 * res - 1;
    else return 2 * res + 1;
}
 
void Solve(){
    int n, k; cin >> n >> k;
    cout << cal(n, k) << el;
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    if(fopen("ROBERT.INP","r")){
        freopen("ROBERT.INP","r",stdin);
        freopen("ROBERT.OUT","w",stdout);
    }
    int nTest = 1; cin >> nTest;
    while(nTest--) Solve();
}