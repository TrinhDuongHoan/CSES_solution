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
 
int n, m;
vector<int> adj[maxn];
int used[maxn], parent[maxn], st, ed;
 
 
bool dfs(int u){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]) {
            parent[v] = u;
            if(dfs(v)) return true;
        }
        else if (v != parent[u]) {
            st = v, ed = u;
            return true;
        }
    }
    return false;
}
 
void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!used[i]) {
            if(dfs(i)){
                vector<int> cycle;
                while(ed != st){
                    cycle.push_back(ed);
                    ed = parent[ed];
                }
                cycle.push_back(st);
                reverse(all(cycle));
                cycle.push_back(st);
                cout << sz(cycle) << el;
                for(int x : cycle) cout << x << ' ' ;
                return ;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
 
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--){ Solve();}
}