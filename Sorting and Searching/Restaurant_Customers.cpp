#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
 
int n;
int a[maxn], b[maxn];
 
void Solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >>a[i] >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int id1 = 1, id2 = 1;
    int cnt = 0, res = 0, cur = 0;
    while(id1 <= n){
        if(a[id1] < b[id2]) cnt++, id1++;
        else cnt--, id2++;
        res = max(res,cnt);
    }
    cout << res << el;
 
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}