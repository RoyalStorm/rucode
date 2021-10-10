#include <bits/stdc++.h>

#define int int64_t

using namespace std;


int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n, m;
    vector<bool> used;
    vector < vector < pair<int,int> > > g;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    cin >> n >> m;
    g.assign(n, vector<pair<int, int>>());
    used.assign(n, false);
    for(int i = 0; i < m; i++){
        int v, u, c;
        cin >> v >> u >> c;
        v--, u--;
        g[v].emplace_back(u, c);
        g[u].emplace_back(v, c);
    }
    q.emplace(0, 0);
    int w = 0;
    while(!q.empty()){
        auto [cost, v] = q.top();
        q.pop();
        if(used[v])
            continue;
        used[v] = true;
        w += cost;
        for(auto [u, len] : g[v])
            if(!used[u])
                q.emplace(len, u);
    }
    cout << w;
}









#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <bitset>
#include <tuple>

#define ll long long
#define ld long double
#define vll vector<vector<ll>>
#define vd vector<ld>
#define vi vector<int>
#define vdd vector<vector<ld>>
#define vl vector<ll>
#define fi(a, n) for(ll i = (a); i < (n); ++i)
#define fj(a, n) for(ll j = (a); j < (n); ++j)

const ld EPS = 1e-9;
const ll mod = 1e9+7;

using namespace std;

struct dsu{
    vi p;
    vi size;
    dsu(int n = 0){
        p.resize(n);
        size.resize(n, 1);
        fi(0, n){
            p[i] = i;
        }
    }
    int get(int v){
        if(v == p[v]){
            return p[v];
        }
        p[v] = get(p[v]);
        return p[v];
    }
    void _union(int u, int v){
        u = get(u);
        v = get(v);
        if(u == v){
            return;
        }
        if(size[u] > size[v])
            swap(u, v);
        p[u] = v;
        size[v] += size[u];
    }
};

struct edge{
    int from, to, w;
    edge(int _from=0, int _to=0, int _w=0){
        from = _from;
        to = _to;
        _w = w;
    }
    bool operator <(const edge& e) const{
        return w < e.w;
    }
};
istream& operator >> (istream& in, edge& e){
    in >> e.from >> e.to >> e.w;
    --e.from;
    --e.to;
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    for(auto &e: edges){
        cin >> e;
    }
    sort(edges.begin(), edges.end());

    dsu d(n);
    int ans = 0;
    for(auto &e: edges){
        if(d.get(e.from) != d.get(e.to)){
            d._union(e.from, e.to);
            ans += e.w;
        }
    }
    
    cout << ans << '\n';

    return 0;
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
vector<pair<int, pair<int, int>>> r;
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
    int m;
    cin >> n >> m;
    parent = vector<int>(n);
    sz = vector<int>(n);
    init_sets();
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        //union_sets(x, y);
        r.push_back({ w, {x-1, y-1} });
    }
    int ans = 0;
    sort(r.begin(), r.end());
    for (auto reb : r)
    {
        if (get_parent(reb.second.first) != get_parent(reb.second.second))
        {
            ans += reb.first;
            union_sets(reb.second.first, reb.second.second);
        }
    }
    cout << ans << '\n';
}