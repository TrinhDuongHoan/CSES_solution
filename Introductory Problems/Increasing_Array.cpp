#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define spc(x) fixed << setprecision(x)
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5;
 
void solve()
{
	int n;
	cin >> n;
	int res = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
			res += (a[i - 1] - a[i]), a[i] += (a[i - 1] - a[i]);
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