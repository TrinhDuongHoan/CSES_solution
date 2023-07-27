#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define spc(x) fixed << setprecision(x)
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5;
 
void solve()
{
	string s;
	cin >> s;
	int i = 0, res = 0;
	while (i < s.size())
	{
		int l = 1;
		while (s[i] == s[i + 1])
			l++, i++;
		res = max(res, l);
		i++;
	}
	cout << res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t = 1; // cin >> t;
	while (t--)
		solve();
}