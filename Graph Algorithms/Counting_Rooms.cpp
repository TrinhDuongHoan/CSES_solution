#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
 
char a[1005][1005];
bool visited[1005][1005];
 
int n, m;
 
void dfs(int i, int j){
    visited[i][j] = true;
    for(int k = 0 ; k < 4; ++k){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y] && a[x][y] =='.' )
            dfs(x,y);
    }
}
 
void Solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!visited[i][j] && a[i][j] == '.') cnt++, dfs(i,j);
        }
    }
    cout << cnt ;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}