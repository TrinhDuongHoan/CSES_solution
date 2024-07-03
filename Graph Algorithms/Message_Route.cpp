#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e5+5;
 
int n,m;
vector<pair<int,int>> G[maxn];
int trace[maxn];
 
void dijkstra(int s){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> d(n+1,inf);
    d[s] = 0 ;
    pq.push({0,s});
    while(!pq.empty()){
        pair<int,int> tp = pq.top();pq.pop();
        int u = tp.second;
        int W = tp.first;
        if(W > d[u]) continue;
        for(pair<int,int> e : G[u]){
            int v = e.first;
            int w = e.second;
            if(d[v] > d[u]+w){
                d[v] = d[u] + w;
                trace[v] = u;
                pq.push({d[v],v});
            }
        }
    }
    // for(int i =1; i <= n; ++i) cout << d[i] << ' ';
    if(d[n] == inf) cout << "IMPOSSIBLE";
    else{
        int u = n;
        vector<int> res;
        while(u != 1){
            res.push_back(u);
            u = trace[u];
        }
        res.push_back(1);
        reverse(all(res));
        cout << (int) res.size() << '\n';
        for(int i = 0 ; i < (int) res.size(); ++i) cout << res[i] << ' ';
    }
}
 
void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v ;
        G[u].push_back({v,1});
        G[v].push_back({u,1});
    }
    dijkstra(1);
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}
