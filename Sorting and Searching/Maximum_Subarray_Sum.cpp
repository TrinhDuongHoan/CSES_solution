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
int a[maxn];
 
void Solve() {
    int sum = 0, max_sum = -inf, max_ele = -inf;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], max_ele = max(max_ele,a[i]);
    if(max_ele < 0){
        cout << max_ele ;
        return;
    }
    for(int i = 1; i <= n; ++i){
        sum += a[i];
        if(sum < 0) sum = 0;
        max_sum = max(max_sum,sum);
    }
    cout << max(max_sum,max_ele);
 
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}