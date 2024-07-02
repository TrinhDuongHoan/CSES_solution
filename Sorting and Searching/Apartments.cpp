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
    int n,m,k; cin >> n >> m >> k;
    vector<int> apartment(n);
    vector<int> cus(m);
    for(int i = 0 ; i < n; ++i) cin >> apartment[i];
    for(int i= 0 ; i < m; ++i) cin >> cus[i];
    sort(all(apartment));
    sort(all(cus));
    int i = n-1,j=m-1,cnt =0;
    while(i >= 0 && j >= 0){
        if(abs(cus[j]-apartment[i]) <= k ) i--,j--,cnt++;
        else if (cus[j] > apartment[i]) j--;
        else i--;
    }
    cout << cnt ;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}
