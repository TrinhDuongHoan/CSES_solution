#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;

vector<array<int, 3>> edge;

void Solve(){
    int n,m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    vector<int> d(n + 1, inf);

    d[1] = 0;

    vector<int> p(n + 1, -1);

    for(int i = 1; i <= n; i++){
        for(auto e: edge){
            int u = e[0], v = e[1], w = e[2];
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    for(auto e: edge){
        int u = e[0], v = e[1], w = e[2];
        if(d[u] + w < d[v]){
            cout << "YES" << el;
            vector<int> path;
            for(int i = 0; i < n; i++) v = p[v];
            for(int i = v; ; i = p[i]){
                path.push_back(i);
                if(i == v && path.size() > 1) break;
            }
            reverse(all(path));
            for(auto x: path) cout << x << ' ';
            cout << el;
            return;
        }
    }
    cout << "NO" << el;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    if(fopen("ROBERT.INP","r")){
        freopen("ROBERT.INP","r",stdin);
        freopen("ROBERT.OUT","w",stdout);
    }
    int nTest = 1; //cin >> Test;
    while(nTest--) Solve();
}