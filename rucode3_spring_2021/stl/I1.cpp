#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> graph;

pair<int, vector<int>> dijkstra(int s, int f, int n) {
    vector<bool> used(n, false);
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> queue;
    vector<int> vertexes_history(n);

    queue.insert({s, 0});
    vertexes_history[s] = -1;

    while (!queue.empty()) {
        int cur_v = queue.begin()->first;
        int distance = queue.begin()->second;
        queue.erase({cur_v, distance});

        dist[cur_v] = distance;

        for (auto p : graph[cur_v]) {
            int to = p.first;
            int weight = p.second;

            if (dist[cur_v] + weight >= dist[to])
                continue;

            queue.erase({to, dist[to]});
            queue.insert({to, dist[cur_v] + weight});
            dist[to] = dist[cur_v] + weight;

            vertexes_history[to] = cur_v;
        }
    }

    int end = f;
    if (dist[end] == INT_MAX)
        return {-1, vector<int>(n)};

    vector<int> path;
    while (end != -1) {
        path.push_back(end);
        end = vertexes_history[end];
    }

    reverse(path.begin(), path.end());

    return {dist[f], path};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int s, f;
    cin >> s >> f;
    s--;
    f--;

    graph = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;

        b--;
        e--;

        graph[b].push_back({e, w});
        graph[e].push_back({b, w});
    }

    pair<int, vector<int>> res = dijkstra(s, f, n);

    if (res.first > -1)
    	cout << res.first << endl;
    else
        cout << -1;

    return 0;
}