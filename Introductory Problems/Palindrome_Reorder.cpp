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
    string s, ans = "",ans2="";
    map<char,int> mp;
    cin >> s;
    for(int i = 0 ; i < s.size(); ++i){
        mp[s[i]]++;
 
    }
    int cnt = 0;
    char c;
    for(auto x: mp){
        if(x.second&1) cnt++, c = x.first;
        if(cnt == 2){
            cout << "NO SOLUTION";
            return;
        }
    }
    if(cnt&1){
        for(auto x : mp){
            if(x.second % 2 == 0){
                for(int i = 1; i <= x.second/2; ++i){
                    ans+=x.first;
                }
            }
        }
        for(int i = 1; i <= mp[c]; ++i)ans+=c;
        for(auto x : mp){
            if(x.second % 2 == 0){
                for(int i = 1; i <= x.second/2; ++i){
                    ans2+=x.first;
                }
            }
        }
    }
    else {
        for(auto x : mp){
            if(x.second % 2 == 0){
                for(int i = 1; i <= x.second/2; ++i){
                    ans+=x.first;
                }
            }
        }
        for(auto x : mp){
            if(x.second % 2 == 0){
                for(int i = 1; i <= x.second/2; ++i){
                    ans2+=x.first;
                }
            }
        }
    }
    reverse(ans2.begin(), ans2.end());
    cout << ans << ans2;
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //in >> T;
    while(T--) Solve();
}