#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 2e5+5;
 
int n,k;
int a[N];
 
int good(int m){
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        cnt+= (m/a[i]);
        if(cnt >= k) return 1;
    }
    return cnt >= k;
}
 
signed main(){
    int ans;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int l = 0 , r = 1e18;
    while(l <= r){
        int mid = l+r >> 1;
        if(good(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    cout << ans;
}