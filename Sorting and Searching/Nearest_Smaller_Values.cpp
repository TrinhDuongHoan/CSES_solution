/*===============================================
 _____   ____  ____  ______ _____ _______ 
 |  __ \ / __ \|  _ \|  ____|  __ \__   __|
 | |__) | |  | | |_) | |__  | |__) | | |   
 |  _  /| |  | |  _ <|  __| |  _  /  | |   
 | | \ \| |__| | |_) | |____| | \ \  | |   
 |_|  \_\\____/|____/|______|_|  \_\ |_|                                
 
=================================================*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define int long long
#define el '\n'
 
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
const int LOG = 20;
 
int n, a[MAXN], pos[MAXN];
 
void Test_Case(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        int id = i-1;
        while(a[id] >= a[i]){
            id = pos[id];
        }
        pos[i] = id;
    }
    for(int i = 1; i <= n; ++i) cout << pos[i] << ' ';
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int Test = 1;// cin >> Test;
    while(Test--) Test_Case();
}
