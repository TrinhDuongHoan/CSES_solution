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
const int inf = 1e15;

vector<pair<int,int>> adj[maxn];
int n, m, dist[maxn][2];



void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    for(int i =1; i <= n; ++i) dist[i][0] = dist[i][1] = inf;
    dist[1][0] = 0;
    min_heap<array<int,3>> pq;

    pq.push({0,1,0});

    while(!pq.empty()){
        auto [W,u,used] = pq.top(); pq.pop();

        int cur_dist = dist[u][used];
        if(cur_dist != W) continue;
        if(u == n) break;

        for(auto [v,w] : adj[u]){
            if(!used){
                int new_dist = cur_dist + w/2;
                if(new_dist < dist[v][1]){
                    dist[v][1] = new_dist;
                    pq.push({dist[v][1],v,1});
                }
            }

            if(cur_dist + w < dist[v][used]){
                dist[v][used] = cur_dist + w;
                pq.push({dist[v][used], v, used});
            }
        }
    }

    cout << dist[n][1] ;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--){ Solve();}
}