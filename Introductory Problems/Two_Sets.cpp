#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 1e6+5;
const int mod = 1e9+7;
 
void Solve() {
    vector<int> a,b;
    int n; cin >> n;
    if(n*(n+1)%4 != 0){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        if(n%2 == 0){
            int val = 1;
            for(int i = 1; i <= n/4; ++i) a.push_back(val), a.push_back(n+1-val),val++;
            for(int i = 1; i <= n/4; ++i) b.push_back(val), b.push_back(n+1-val),val++;
        }
        else{
            int val = 1;
            for(int i = 1; i <= (n+1)/4; ++i) a.push_back(val), a.push_back(n-val),val++;
            for(int i = 1; i <= n/4; ++i) b.push_back(val), b.push_back(n-val),val++;
            b.push_back(n);
        }
        cout << b.size() << el;
        for(int i = 0 ; i < b.size(); ++i) cout << b[i] << ' ';cout << el;
        cout << a.size() << el;
        for(int i = 0 ; i < a.size(); ++i) cout << a[i] << ' '; cout << el;
 
    }
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}