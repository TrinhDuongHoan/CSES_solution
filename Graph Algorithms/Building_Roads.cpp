#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << el;
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,1,-1,0};
 
vector<int> g[maxn], brige;
int n, m, used[maxn];
 
void dfs(int u){
    used[u] = 1;
    for(int v : g[u]) if(!used[v]) dfs(v);
}
 
void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m ; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i =1; i <= n; ++i){
        if(!used[i]) brige.push_back(i), dfs(i);
    }
    cout << (int) brige.size()-1 << el;
    for(int i = 0 ; i < (int) brige.size()-1; ++i){
        cout << brige[i] << ' ' << brige[i+1] << '\n';
    }
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;//  cin >> T;
    while (T--) Solve();
}
