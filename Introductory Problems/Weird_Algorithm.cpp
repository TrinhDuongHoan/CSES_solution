#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define spc(x) fixed << setprecision(x)
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5;
 
int pre[N];
 
void solve()
{
	int n;
	cin >> n;
	cout << n;
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		cout << " " << n;
	}
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