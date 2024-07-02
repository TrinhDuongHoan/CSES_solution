#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int n;
multiset<int> a;
 
void Solve(){
    cin >> n;
    for(int i = 1,x; i <= n; ++i){
        cin >> x;
        auto it = a.upper_bound(x);
        if(it != a.end()) a.erase(it);
        a.insert(x);
    }
    cout << (int)a.size();
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) Solve();
}