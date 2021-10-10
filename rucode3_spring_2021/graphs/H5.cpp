#include <bits/stdc++.h>

using namespace std;


int p[100000];
int rk[100000];

void init_dsu() {
    for (int i = 0; i < 100000; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int get_root(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = get_root(p[v]);
    }
}

bool merge(int a, int b) {
    int ra = get_root(a), rb = get_root(b);

    if (ra == rb) {
        return false;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }

        return true;
    }
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    init_dsu();
    while (m--){
        int u, v;
        cin >> u >> v;
    }
    vector<pair<string, pair<int, int>>> q;
    while(k--){
        string s;
        int u, v;
        cin >> s >> u >> v;
        q.emplace_back(s, make_pair(u, v));
    }
    stack<bool> st;
    while(!q.empty()){
        string s = q.back().first;
        int u = q.back().second.first, v = q.back().second.second;
        q.pop_back();
        if(s == "cut")
            merge(u, v);
        else
            st.push(get_root(u) == get_root(v));
    }
    while(!st.empty()){
        cout << (st.top() ? "YES\n" : "NO\n");
        st.pop();
    }
}









#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

typedef unsigned long long ull;
vector<int> parent;
vector<int> sz;
vector<pair<string, pair<int, int>>> z;
const int INF = INT_MAX;
int n;

void init_sets() {
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int get_parent(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get_parent(parent[v]);
}

void union_sets(int x, int y)
{
    int a = get_parent(x), b = get_parent(y);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    parent[a] = b;
    sz[b] += sz[a];
}

int main()
{
    int m, k;
    cin >> n >> m >> k;
    parent = vector<int>(n);
    sz = vector<int>(n);
    init_sets();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
    }
    for (int i = 0; i < k; i++)
    {
        string cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (a > b)
            swap(a, b);
        z.push_back({ cmd, {a - 1, b - 1} });
    }
    vector<bool> ans;
    reverse(z.begin(), z.end());
    for (auto zap : z)
    {
        if (zap.first == "ask")
            ans.push_back(get_parent(zap.second.first) == get_parent(zap.second.second));
        else
            union_sets(zap.second.first, zap.second.second);
    }
    reverse(ans.begin(), ans.end());
    for (auto an : ans)
        if (an)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

}