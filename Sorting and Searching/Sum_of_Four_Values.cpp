#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define duonghoan21 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
int n,x;
int a[maxn];
 
void Solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            mp[a[i] + a[j]] = {i,j};
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            int X = x - a[i] - a[j];
            if (mp.count(X)) {
                pair<int, int> id = mp[X];
                if (j < id.first) {
                    cout << i << ' ' << j << ' ' << id.first << ' ' << id.second;
                    return ;
                }
            }
        }
 
    cout << "IMPOSSIBLE";
}
 
signed main(){
    duonghoan21
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int t = 1;  //cin >> t;
    while (t--) Solve();
}