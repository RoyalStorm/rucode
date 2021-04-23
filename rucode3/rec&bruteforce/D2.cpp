#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = INT_MAX;
const int mod = 1e9 + 7;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    vector < vector < int > > dp (n + 1, vector < int > (n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < n; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        dp[i][n] = dp[i - 1][n - 1];
    }
    int ans = 1, bal = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == ')')
        {
            --bal;
            ans += dp[n - i - 1][bal + 2];
            ans %= mod;
        }
        else
            ++bal;
    }
    cout << ans << "\n";
}

int main()
{
    bust;
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while (t--)
        solve();
	return 0;
}







#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = INT_MAX;
const int mod = 1e9 + 7;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    vector < vector < int > > dp (n + 1, vector < int > (n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < n; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        dp[i][n] = dp[i - 1][n - 1];
    }
    int ans = 1, bal = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == ')')
        {
            --bal;
            ans += dp[n - i - 1][bal + 2];
            ans %= mod;
        }
        else
            ++bal;
    }
    cout << ans << "\n";
}

int main()
{
    bust;
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while (t--)
        solve();
	return 0;
}








#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#include <queue>
#include <ctime>
using namespace std;

#define ll unsigned long long
vector<vector<ll>> dp;
const ll mod = 1E9 + 7;
ll res = 0, bal = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	dp.resize(s.length() + 1, vector<ll>(s.length() + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			if (j > 0)dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
			if (j + 1 < dp[i].size())dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')bal++;
		else {
			res = (res + dp[s.length() - i - 1][bal + 1]) % mod;
			bal--;
		}
	}
	cout << (res + 1) % mod << "\n";
	return 0;

}