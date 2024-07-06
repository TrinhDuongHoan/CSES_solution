#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;

int divisor[maxn];

void cal(){
    for(int i = 1; i < maxn; i++){
        for(int j = i; j < maxn; j += i){
            divisor[j]++;
        }
    }
}

void Solve(){
    cal();
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << divisor[x] << el;
    }
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