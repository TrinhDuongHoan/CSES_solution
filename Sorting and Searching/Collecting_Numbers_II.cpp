#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int n,m;
int a[maxn], pos[maxn];
set<pair<int,int>> update; 
 
void Solve(){
    
    cin >> n >> m;
    for(int i =1; i <= n; ++i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans =1;
    for(int i =1; i < n; ++i){
        if(pos[i] > pos[i+1]) ++ans;
    }
    for(int i =1,l,r; i <= m; ++i){
        cin >> l >> r;
        if(a[l] + 1 <= n)  update.insert({a[l], a[l]+1});
        if(a[l] - 1 >= 1)  update.insert({a[l]-1, a[l]});
        if(a[r] -  1 <= n)  update.insert({a[r], a[r]+1});
        if(a[r] -  1 >= 1)  update.insert({a[r]-1, a[r]});
        for(auto x : update){
            ans -= (pos[x.first] > pos[x.second]);
        }
        swap(a[l],a[r]);
        pos[a[l]] = l;
        pos[a[r]] = r;
        for(auto x : update){
            ans += (pos[x.first] > pos[x.second]);
        }
        cout << ans << '\n';
        update.clear();
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