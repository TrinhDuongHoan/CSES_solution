#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
string a[8];
 
void Solve() {
    int ans = 0;
    for(int i = 0 ; i < 8; ++i){
        cin >>a[i];
    }
    int p[8];
    bool b[15];
    iota(p,p+8,0); // ham fill gia  tri tang dan tu 0
    do{
        bool ok = 1;
        for(int i = 0 ; i < 8; ++i){
            ok&= a[i][p[i]] == '.';
        }
        memset(b,0,15);
        for(int i = 0 ; i < 8; ++i ){
            if(b[i+p[i]]) ok = 0;
            b[i+p[i]] = 1;
        }
        memset(b,0,15);
        for(int i = 0 ; i < 8; ++i ){
            if(b[i+7-p[i]]) ok = 0;
            b[i+7-p[i]] = 1;
        }
        ans += ok;
    }while(next_permutation(p,p+8));
     cout << ans << el;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}
