#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define el '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define _Robert_ main
using namespace std;
 
const int maxn = 2e5+5;
const int mod = 1e9+7;
 
int n;
 
void Solve() {
    int cnt_movies = 0, cur_time = 0;
    cin >> n;
    vector<pair<int,int>> movies(n);
    for(int i= 0 ; i < n; ++i){
        cin >> movies[i].second >> movies[i].first;
    }
    sort(all(movies));
    for(auto x: movies){
        if(x.second >= cur_time){
            cur_time = x.first;
            cnt_movies++;
        }
    }
    cout << cnt_movies ;
 
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while(T--) Solve();
}