#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
#include <cmath>

using namespace std;

vector<pair<int, int> > gr[1001];
vector<pair<int, int> > gr_new[1001];
int dist[1001];
int parent[1001];
bool used[1001];

int dfs(int x, int min_pr, int w, int b, vector<int> & v){
    v[x] = min(min_pr, w);
    if (x == b){
        return v[b];
    }
    for (auto elem : gr_new[x]){
        if (v[elem.first] == -1){
            int c = dfs(elem.first, v[x], elem.second, b, v);
            if (c != -1){
                return c;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    int v, u, w;
    for (int i = 0; i < m; ++i){
        cin >> v >> u >> w;
        gr[u - 1].push_back(make_pair(v - 1, w));
        gr[v - 1].push_back(make_pair(u - 1, w));
    }
    parent[0] = -1;
    dist[0] = 201;
    set<pair<int, int>, greater<> > h;
    h.emplace(dist[0], 0);
    while (!h.empty()){
        v = h.begin() -> second;
        used[v] = true;
        if (parent[v] != -1) {
            gr_new[parent[v]].push_back(make_pair(v, h.begin()->first));
            gr_new[v].push_back(make_pair(parent[v], h.begin()->first));
        }
        h.erase(h.begin());
        for (auto elem : gr[v]){
            if (!used[elem.first]){
                u = elem.first;
                w = elem.second;
                if (dist[u] < w){
                    h.erase(make_pair(dist[u], u));
                    dist[u] = w;
                    h.emplace(dist[u], u);
                    parent[u] = v;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i){
        cin >> v >> u;
        vector<int> tmp(n + 1, -1);
        cout << dfs(v - 1, 201, 201, u - 1, tmp) << "\n";
    }
    return 0;
}





#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <set>
#include <iterator>
#include <map>
#include <iomanip>
//#define int long long
#define fir first
#define sec second
#define pb push_back
#define double long double
#define endl "\n"
#define un unsigned
#define INF 1000000000
using namespace std;
 
int n, m, k;
vector<pair<int, int>> gr[10000];
vector <vector<pair<int, int>>> g(10000);
 
int s, f;
int dist[10005];
pair<int,int> pr[10005];
 
void BFS(int v, int fin)
{
    fill(dist, dist + 10000, -1);
    
    memset(pr, 0, 10000);
 
    dist[v] = 0;
 
    queue <pair<int,int>> q;
 
    q.push({ v,INF });
 
    int maxim = INF;
 
    while (q.size() > 0)
    {
        pair<int,int> u = q.front();
 
        for (pair <int, int> p : g[u.first])
        {
            if (dist[p.first] == -1)
            {
                dist[p.first] = dist[u.first] + 1;
 
                pr[p.first].first = u.first;
 
                if (pr[pr[p.first].first].second == 0)
                {
                    maxim = p.second;
                }
                else
                {
                    maxim = min(p.second, pr[pr[p.first].first].second);
                }
 
                pr[p.first].second = maxim;
 
                q.push(p);
            }
 
            if (p.first == fin)
            {               
                cout << pr[p.first].second << endl;
 
                return;
            }
        }
 
        q.pop();
    }
 
    return;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m >> k;
 
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        gr[a].push_back({ b, w });
        gr[b].push_back({ a, w });
    }
 
    vector<int> max_e(n, -1); // вес минимального ребра из чёрной вершины в любую зелёную
    vector<int> sel_e(n, -1); // куда ведёт ^ минимальное ребро из чёрной вершины в зелёную
    vector<int> used(n, 0); // зeлeные вершины
 
    max_e[0] = 0;
 
    int mst = 0;
 
    set<pair<int, int>> q; // { weight_edge, to }
 
    q.insert({ 0, 0 });
 
    for (int i = 0; i < n; ++i)
    {
        int v = (--q.end())->second;
        q.erase(--q.end());
 
        if (i != 0)
        {
            g[sel_e[v]].push_back({ v, max_e[v] });
            g[v].push_back({ sel_e[v], max_e[v] });
        }
        mst += max_e[v];
        used[v] = 1;
 
        for (int i = 0; i < gr[v].size(); i++)
        {
            int u = gr[v][i].fir;
            int w = gr[v][i].sec;
 
            if (!used[u] && max_e[u] < w)
            {
                q.erase({ max_e[u], u });
 
                max_e[u] = w;
                sel_e[u] = v;
 
                q.insert({ max_e[u], u });
            }
        }
    }
 
    /*for (int i = 0; i < n; i++)
    {
        if (sel_e[i] != -1)
        {
            g[sel_e[i]].pb({ i, max_e[i] });
            g[i].pb({ sel_e[i], max_e[i] });
        }       
    }*/
 
    for (int i = 0; i < k; i++)
    {
        cin >> s >> f;
 
        s--;
        f--;
 
        BFS(s, f);
    }
 
    return 0;
}