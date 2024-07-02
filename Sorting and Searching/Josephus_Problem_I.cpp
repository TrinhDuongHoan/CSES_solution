#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define Robert ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(a) cout << #a << ':' << a << endl;
#define inf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
const int maxn=1e6+5;
 
int n;
 
void Solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; ++i) a[i] = i+1;
    while((int) a.size() > 1){
        vector<int> sur;
        for(int i = 0 ; i < (int)a.size(); ++i){
            if(i&1) cout << a[i] << ' ';
            else sur.push_back(a[i]);
        } 
        if((int)a.size() % 2 == 0){
            a = sur;
        }
        else {
            int last = sur.back();
            sur.pop_back();
            a.clear();
            a.push_back(last);
            for(int x : sur) a.push_back(x);
        }
    }
    cout << a[0];
}
signed main(){  
    Robert
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
    int T = 1; // cin >> T;
    while (T--) Solve();
}