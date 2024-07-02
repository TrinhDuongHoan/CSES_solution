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
int id[maxn];
 
void Solve() {
    cin >> n;
    for(int i = 1,x; i <= n; ++i){
        cin >> x;
        id[x] = i;
    }
    int r = 1,res = 1;
    for(int i = 1; i <= n; ++i){
        if(res > id[i]) r++;
        res = id[i];
    }
    cout << r ;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}
