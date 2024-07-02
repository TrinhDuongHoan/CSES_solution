#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
 
int n,m,x;
multiset<int> h;
 
void Solve() {
    cin >> n>> m;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        h.insert(x);
    }
    for(int i = 1; i <= m ;++i){
        cin >> x;
        if(h.empty()){
            cout << -1<<el;
            continue;
        }
        auto it = h.upper_bound(x);
        if(it == h.begin()) cout << -1 << el;
        else {
                cout << *(--it) << el;
                h.erase(it);
        }
    }
 
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}