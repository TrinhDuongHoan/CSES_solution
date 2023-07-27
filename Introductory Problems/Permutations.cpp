#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define duonghoan21 ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
const int MOD = 1e9+7;
const int MAXN = 1e7+5;
const int N = 1e5+4;
 
 
 
void Solve()
{
    int n; cin >> n;
    if (n == 1) cout << 1;
    else if (n <= 3) cout << "NO SOLUTION";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if(!(i&1)) cout << i << " ";
        }
        for (int i = 1; i <= n ; i++ )
        {
            if (i&1) cout << i << " ";
        }
    }
}
signed main()
{
    duonghoan21;
    int tc = 1; //cin >> tc;
    while(tc--)
    {
        Solve();
    }
 
}