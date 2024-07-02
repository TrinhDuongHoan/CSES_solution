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
    int n;
    cin >> n;
    vector<string> gray_code;
    gray_code.push_back("");
    for (int i = 0; i < n; i++) {
        int size = gray_code.size();
        for (int j = size - 1; j >= 0; j--) {
            gray_code.push_back(gray_code[j]);
        }
        size *= 2;
        for (int j = 0; j < size; j++) {
            if (j < gray_code.size() / 2) {
                gray_code[j] += "0";
            } else {
                gray_code[j] += "1";
            }
        }
    }
    for (int i = 0; i < gray_code.size(); i++) {
        cout << gray_code[i] << endl;
    }
}
_Robert_(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T = 1; //cin >> T;
    while(T--) Solve();
}