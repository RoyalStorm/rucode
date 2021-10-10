#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int g[n + 1][n + 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    g[n][n] = 0;
    for(int i = 0; i < n; i++){
        cin >> g[n][i];
        g[i][n] = g[n][i];
    }
    bool used[n + 1];
    memset(used, false, sizeof used);
    int min_e[n + 1];
    for(int i = 0; i <= n; i++)
        min_e[i] = LLONG_MAX;
    int sel_e[n + 1];
    memset(sel_e, -1, sizeof sel_e);
    min_e[0] = 0;
    for (int i=0; i<=n; ++i) {
        int v = -1;
        for (int j=0; j<=n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        used[v] = true;
        for (int to=0; to<=n; ++to)
            if (!used[to] && v != to && g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    int w = 0;
    for(auto i: min_e)
        w += i;
    cout << w;
}








#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <iomanip>
#define pii pair<int, int>

using namespace std;
const int INF = 1e9;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    g[n][n] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> g[n][i];
        g[i][n] = g[n][i];
    }
    vector<int> used(n+1);
    vector<int> d(n+1, INF);
    d[n] = 0;
    ull ans = 0;
    for (int k = 0; k <= n; k++)
    {
        int v;
        bool flag = true;
        for (int i= 0; i<=n; i++)
            if (!used[i] && (flag || d[v] > d[i]))
            {
                flag = false;
                v = i;
            }
        used[v] = true;
        ans += d[v];
        for (int to = 0; to <= n; to++)
            if (v != to && g[v][to] < d[to])
                d[to] = g[v][to];
    }
    cout << ans << '\n';
}