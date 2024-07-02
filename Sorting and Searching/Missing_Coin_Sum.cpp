#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
int n;
int a[maxn], prefix[maxn];
 
void Solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1,a+1+n);
    prefix[0] = 1;
    for(int i = 1; i <= n; ++i){
        if(prefix[i-1] < a[i]){
            cout << prefix[i-1];
            return;
        }
        prefix[i] = prefix[i-1]+a[i];
    }
    cout << prefix[n];
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}