#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
#define spc(x) fixed << setprecision(x)
const int MOD = 1e9 + 7;
const int MAXN=1e6+5;
const int N=1e5+4;

set<string> ans;

void permutations(string prefix, string suffix)
{
    if (suffix.length() == 0)
    {
        ans.insert(prefix);
        return;
    }
    for (int i = 0; i < suffix.length(); i++)
    {
        permutations(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}
void Solve()
{
    string s;
    cin >> s;
    permutations("", s);
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;  //cin >> t;
    while (t--) Solve();
}