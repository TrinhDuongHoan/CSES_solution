#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int n; 
int a[maxn];
 
void Solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    map<int,int> mp;
    int ans = 0;
    for(int i = 1,j = 0; i <= n; ++i){
        while(j+1 <= n && mp[a[j+1]] == 0){
            ++j;
            mp[a[j]] = 1;
        }
        ans = max(ans, j-i+1);
        mp[a[i]] = 0;
    }
    cout << ans;
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1;  //cin >> T;
    while (T--) Solve();
}