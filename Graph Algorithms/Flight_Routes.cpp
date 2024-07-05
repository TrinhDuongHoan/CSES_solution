#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define el '\n'
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e17;

vector<array<int, 2>> g[maxn];

template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int dp[maxn][11], n, m,k;

void Dijkstra(int s){
    min_heap<array<int, 2>> pq; 

    for(int i =1; i <= n; ++i){
        for(int j = 1; j <= k ; ++j) dp[i][j] = inf;
    }

    pq.push({0,s});

    while(!pq.empty()){
        auto [W,u] = pq.top(); pq.pop();

        if(W > dp[u][k]) continue;

        for(auto [v,w] : g[u]){
            for(int i = 1; i <= k; ++i){
                if(dp[v][i] > W + w){
                    for(int j = k; j > i; --j){
                        dp[v][j] = dp[v][j-1];
                    }
                    dp[v][i] = W+w;
                    pq.push({dp[v][i],v});
                    break;
                }
            }
        }
    }
}

void Solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    Dijkstra(1);
    for(int i = 1; i <= k; i++){
        cout << dp[n][i] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    if(fopen("ROBERT.INP","r")){
        freopen("ROBERT.INP","r",stdin);
        freopen("ROBERT.OUT","w",stdout);
    }
    int nTest = 1; //cin >> nTest;
    while(nTest--) Solve();
}