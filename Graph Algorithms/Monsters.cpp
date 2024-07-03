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
 
const int dx[4] = {0,-1,1,0};
const int dy[4] = {1,0,0,-1};
string step = "RUDL";
 
int n, m, x_st, y_st; 
queue<pair<int,int>> q;
char a[1005][1005];
int used[1005][1005], trace[1005][1005];
 
void bfs(int i, int j){
    q.push({i,j});
    used[i][j] = 1;
 
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        if(a[x][y] == 'A'){
            if(x == 1 || x == n || y == 1 || y == m){
                cout << "YES\n";
                string ans = "";
                int d = trace[x][y];
                while(d != -1){
                    ans += step[d];
                    x -= dx[d];
                    y -= dy[d];
                    d = trace[x][y];
                }
                reverse(all(ans));
                cout << sz(ans) << el;
                cout << ans ;
                return ;
            }
        }
 
        for(int i = 0;  i< 4 ;++i){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] == '.'){
                a[xx][yy] = a[x][y];
                if(a[xx][yy] == 'A') trace[xx][yy] = i;
                q.push({xx,yy});
            }
        }
    }
 
    cout << "NO";
}
 
void Solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m ; ++j){
            cin >> a[i][j];
            if(a[i][j] == 'M') q.push({i,j});
            else if (a[i][j] == 'A') x_st = i, y_st = j;
        }
    }
    trace[x_st][y_st] = -1;
    bfs(x_st,y_st);
}
 
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--){ Solve();}
}