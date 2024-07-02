#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
 
int n,x;
pair<int,int> a[maxn];
 
int bs(int l, int r, int val){
    while(l <= r){
        int mid = l+r >> 1;
        if(a[mid].first == val) return a[mid].second;
        else if (a[mid].first > val) r = mid-1;
        else l = mid+1;
    }
    return 0;
}
 
void Solve() {
    cin >> n >> x;
    for(int i = 1; i <= n;++i) cin >> a[i].first, a[i].second = i;
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; ++i){
        if(bs(i+1,n,x-a[i].first)){
            cout << a[i].second << ' ' << bs(i+1,n,x-a[i].first);
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}