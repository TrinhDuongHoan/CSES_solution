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
 
void Test_Case(){
    int n, k; cin >> n >> k;
    int a[n + 1];
    int l = 1, r = 0, ans ;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        r += a[i];
    }
    while(l <= r){
        int mid = l + r >> 1;
        int cnt_sub = 0, cur_sum = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] > mid){
                cnt_sub = LLONG_MAX-1;
                break;
            }
            if(cur_sum + a[i] > mid) ++cnt_sub, cur_sum = 0;
            cur_sum += a[i];
        }
        if(cur_sum > 0) ++cnt_sub;
        if(cnt_sub <= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans ;
}
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int Test = 1; //cin >> Test;
    while(Test--) Test_Case();
}