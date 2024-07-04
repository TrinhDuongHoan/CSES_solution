#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define fi first 
#define se second
#define BIT(x, i) (1 & ((x) >> (i)))
#define MASK(x) (1LL << (x))
#define CNT(x) __builtin_popcountll(x)
#define all(a) a.begin(),a.end()
#define sz(a) (int) a.size()
#define el "\n"

template<class T> using max_heap = priority_queue<T>;
template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool minimize(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> inline bool maximize(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5+5;
const int mod = 1e9 + 7;
const int inf = 1e15;

vector<array<int,3>> edge;
int n, m, q, dist[505][505];

void Floyd(){
    for(int i = 1; i <= n ; ++i){
        for(int j = 1; j <= n ; ++j){
            dist[i][j] = inf ;
            if(i == j) dist[i][j] = 0;
        }
    }

    for(auto x : edge){
        auto [u,v,w] = x;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

}

void Solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= m ; ++i){
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u,v,w});
    }

    Floyd();

    for(int i = 1; i <= q; ++i){
        int u, v; cin >> u >> v;
        if(dist[u][v] == inf) cout << -1 << el;
        else cout << dist[u][v] << el;
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--){ Solve();}
}