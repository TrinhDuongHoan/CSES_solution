#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e3+5;
const int N = 1e5+1;
 
int a[maxn], b[maxn];
 
void Solve(){   
   int n,x;
    cin>>n>>x;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    vector<int> dp(x+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=x; j >= 0; j--)
        {
            if(j >= a[i])
                dp[j] = max(dp[j], dp[j-a[i]]+b[i]);    
        }
    }
    cout<< dp[x] <<endl;
}
signed main(){
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) Solve();
}
