#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;

int cnt[maxn];

void Solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i = maxn - 1; i >= 1; i--){
        int sum = 0;
        for(int j = i; j < maxn; j += i){
            sum += cnt[j];
        }
        if(sum >= 2){
            ans = i;
            break;
        }
    }
    cout << ans << el;
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