#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int x,n,f;
 
void Solve(){
    int res = -inf;
    cin >> x >> n;
    set<int> st = {0,x};
    multiset<int> dis = {x};
    for(int i = 1,x; i <= n; ++i){
        cin >> x;
        auto pos1 = st.upper_bound(x);
        auto pos2 = pos1;   
        --pos2;
        dis.erase(dis.find(*pos1-*pos2));
        dis.insert(x-*pos2);
        dis.insert(*pos1-x);
        st.insert(x);
        auto ans = dis.end();
        ans--;
        cout << *ans << ' ';
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
