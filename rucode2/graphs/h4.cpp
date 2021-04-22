#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> graph;

int dijkstra(int s, int n) {
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> queue;

    queue.insert({s, 0});

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
        }
    }

    if (dist[n - 1] == INT_MAX)
        return -1;
    else
        return dist[n - 1];
}

int main() {
    int n, m;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cin >> m;
    graph = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        v1--;
        v2--;

        graph[v1].push_back({v2, cost[v1]});
        graph[v2].push_back({v1, cost[v2]});
    }

    cout << dijkstra(0, n);

    return 0;
}
