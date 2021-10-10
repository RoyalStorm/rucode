#include <bits/stdc++.h>

#define int int64_t

using namespace std;

struct point{
    int x, y;
};

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int g[n + 1][n + 1];
    point a[n];
    for(auto &i: a)
        cin >> i.x >> i.y;
    g[n][n] = 0;
    for(int i = 0; i < n; i++){
        cin >> g[n][i];
        g[i][n] = g[n][i];
    }
    int k[n];
    for(auto &i: k)
        cin >> i;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            g[i][j] = g[j][i] = (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) * (k[i] + k[j]);
    bool used[n + 1];
    memset(used, false, sizeof used);
    int min_e[n + 1];
    for(int i = 0; i <= n; i++)
        min_e[i] = LLONG_MAX;
    int sel_e[n + 1];
    memset(sel_e, -1, sizeof sel_e);
    min_e[0] = 0;
    vector<pair<int, int>> ans;
    for (int i=0; i<=n; ++i) {
        int v = -1;
        for (int j=0; j<=n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        used[v] = true;
        if (sel_e[v] != -1)
            ans.emplace_back(v, sel_e[v]);
        for (int to=0; to<=n; ++to)
            if (!used[to] && v != to && g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    int w = 0;
    for(auto i: min_e)
        w += i;
    cout << w << '\n';
    vector<int> f;
    vector<pair<int, int>> s;
    for(auto i: ans) {
        if (i.first == n || i.second == n)
            f.emplace_back(i.first == n ? i.second : i.first);
        else
            s.push_back(i);
    }
    cout << f.size() << '\n';
    for(auto i: f)
        cout << i + 1 << ' ';
    cout << '\n';
    cout << s.size() << '\n';
    for(auto i: s)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}





#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <iomanip>
#define pii pair<int, int>

using namespace std;
const int INF = 1e9+500;
typedef unsigned long long ull;

ull len(pii i, pii j, ull ki, ull kj)
{
    int xi = i.first, yi = i.second, xj = j.first, yj = j.second;
    return (abs(xi - xj) + (ull)abs(yi - yj)) * (ki + kj);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> t(n);
    vector<ull> d(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first >> t[i].second;
        d[i] = INF;
    }
    d[n] = 0;
    vector<ull> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<ull> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    vector<bool> used(n+1);
    vector<int> p(n + 1, -1);
    ull ans = 0;
    vector<int> u;
    vector<pii> R;
    for (int j = 0; j <= n; j++)
    {
        int v;
        bool flag = true;
        for (int i = 0; i <= n; i++)
            if (!used[i] && (flag || d[v] > d[i]))
            {
                flag = false;
                v = i;
            }
        used[v] = true;
        ans += d[v];
        if(p[v]==n)
            u.push_back(v + 1);
        if (p[v] != -1 && v!=n && p[v]!=n)
        {
            int x = v, y = p[v];
            if (x > y)
                swap(x, y);
            R.push_back({ x+1, y+1 });
        }
        for (int to = 0; to <= n; to++)
        {
            if (to == v)
                continue;
            ull r;
            if (v == n)
                r = c[to];
            else if (to == n)
                r = c[v];
            else
                r = len(t[v], t[to], k[v], k[to]);
            if (r < d[to])
            {
                d[to] = r;
                p[to] = v;
            }
        }
    }
    cout << ans << '\n' << u.size() << '\n';
    for (auto city : u)
        cout << city << ' ';
    cout << '\n' << R.size() << '\n';
    for (auto r : R)
        cout << r.first << ' ' << r.second << '\n';
}