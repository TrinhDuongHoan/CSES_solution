#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define spc(x) fixed << setprecision(x)
const int MOD = 1e9 + 7;
const int MAXN=1e6+5;
const int N=1e5+4;

int n,cnt = 0;
vector<pair<int,int>> ans;

void Tower_of_Hanoi(int n,int a, int b, int c)
{
    if (n == 1)
    {
        ans.push_back({a,c});
        ++cnt;
    }
    else
    {
        Tower_of_Hanoi(n-1,a,c,b);
        Tower_of_Hanoi(1,a,b,c);
        Tower_of_Hanoi(n-1,b,a,c);
    }
}

void Solve()
{
   cin >> n;
   Tower_of_Hanoi(n,1,2,3);
   cout << cnt << '\n';
   for(int i = 0; i < (int) ans.size(); i++)
   {
        cout << ans[i].first << " " << ans[i].second<<'\n';
   }
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;  //cin >> t;
    while (t--) Solve();
}