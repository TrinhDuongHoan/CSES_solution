#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
int x,y;
 
void Solve() {
    cin >> x >> y;
    if(x <= y){
        if(y%2 == 0) cout << x+(y-1)*(y-1);
        else cout << y*y-x+1;
    }
    else {
        if(x%2==0) cout << x*x-y+1;
        else cout << (x-1)*(x-1)+y;
    }
    cout << '\n';
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; cin >> T;
    while(T--) Solve();
}