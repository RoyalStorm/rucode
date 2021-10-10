#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
};

double dist(point &a, point &b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    point a[n];
    for(auto &i: a)
        cin >> i.x >> i.y;
    bool used[n];
    memset(used, false, sizeof used);
    double min_e[n];
    for(int i = 0; i < n; i++)
        min_e[i] = 1000000000;
    int sel_e[n];
    memset(sel_e, -1, sizeof sel_e);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        used[v] = true;
        for (int to=0; to<n; ++to)
            if (!used[to] && v != to && dist(a[v], a[to]) < min_e[to]) {
                min_e[to] = dist(a[v], a[to]);
                sel_e[to] = v;
            }
    }
    double w = 0;
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
double pif(pii a, pii b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> t(n);
    vector<double> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first >> t[i].second;
        d[i] = INF;
    }
    d[0] = 0;
    vector<bool> used(n);
    double ans = 0;
    for (int k = 0; k < n; k++)
    {
        int v;
        bool flag = true;
        for (int i=0; i<n; i++)
            if (!used[i] && (flag || d[v] > d[i]))
            {
                flag = false;
                v = i;
            }
        used[v] = true;
        ans += d[v];
        for (int to=0; to<n; to++)
        {
            double f = pif(t[v], t[to]);
            if (t[v] != t[to] && f < d[to])
                d[to] = f;
        }
    }
    cout << fixed << setprecision(20) << ans << '\n';

}