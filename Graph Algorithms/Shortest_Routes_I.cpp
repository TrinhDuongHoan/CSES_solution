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

const int maxn = 1e5+5;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

int n, m;
vector<pair<int,int>> adj[maxn];

void Dijkstra(int s) {
    vector<int> d(n + 1, inf);
    min_heap<pair<int,int>> pq;
    d[s] = 0 ;
    pq.push({0,s});
    while(!pq.empty()){
        auto [W,u] = pq.top(); pq.pop();
        if(d[u] < W) continue;
        for(auto [v,w] : adj[u]){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({d[v],v});
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << d[i] << ' ';
}

void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m ; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    Dijkstra(1);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--){ Solve();}
}