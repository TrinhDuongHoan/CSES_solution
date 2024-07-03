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
 
char a[1005][1005];
int n,m,used[1005][1005], trace[1005][1005];
char step[5] = "URLD";
pair<int,int> start, endd;
 
void bfs(int i, int j){
    queue<pair<int,int>> q;
    used[i][j] = 1;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> p = q.front(); q.pop();
        for(int k = 0 ; k < 4; ++k){
            int i1 = p.first + dx[k];
            int j1 = p.second + dy[k];
            if(i1 >= 0 && i1 <= n-1&& j1 >= 0 && j1 <= m-1 && used[i1][j1] == 0 && a[i1][j1] != '#'){
                used[i1][j1] = 1;
                trace[i1][j1] = k;
                q.push({i1,j1});
            }
        }
    }
    // cout << used[endd.first][endd.second];
    if(!used[endd.first][endd.second]){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        vector<int> path;
        while(endd != start){
            int p = trace[endd.first][endd.second];
            path.push_back(p);
            endd = {endd.first - dx[p], endd.second - dy[p]};
        }
        reverse(all(path));
        cout << (int) path.size() << el;
        for(int v : path) cout << step[v] ;
    }
}
 
void Solve(){
    cin >> n >> m;
    for(int i = 0; i <= n-1; ++i){
        for(int j = 0; j <= m-1; ++j){
            cin >> a[i][j];
            if(a[i][j] == 'A') start.first = i, start.second = j;
            if(a[i][j] == 'B') endd.first = i, endd.second = j;
        }
    }
    bfs(start.first, start.second);
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;//  cin >> T;
    while (T--) Solve();
}