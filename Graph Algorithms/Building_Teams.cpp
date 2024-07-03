#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
vector<int> G[maxn];
int n, m;
int vis[maxn], check = 1 ,color[maxn];
 
void dfs(int u, int par = 0){
    vis[u] = 1;
    for(int v : G[u]){
        if(v != par){
            if(!vis[v]){
                color[v] = !color[u];
                vis[v] = 1;
                dfs(v,u);
            }
            else if (color[v] == color[u]) check = 0;
 
        }
    }
}
 
void Solve(){
    cin >> n >> m;
    for(int i =1,x,y; i <= m; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(!check) cout << "IMPOSSIBLE";
    else {
        for(int i = 1; i <= n; ++i){
            cout << (color[i] ? 2 : 1) << ' ';
        }
    }
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}