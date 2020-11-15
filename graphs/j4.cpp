#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int max_couples = 1e7;
const int max_minutes = 1440;
const int truck_weight = 3e6;
const int couple_weight = 100;

vector<vector<pair<int, pair<int, int>>>> graph;

int dijkstra(int s, int n, int couples_weight) {
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
            int t = p.second.first;
            int max_weight = p.second.second;

            if (couples_weight > max_weight || dist[cur_v] + t >= dist[to])
                continue;

            queue.erase({to, dist[to]});
            queue.insert({to, dist[cur_v] + t});
            dist[to] = dist[cur_v] + t;
        }
    }

    return dist[n - 1];
}

int find_optimum(int n) {
    int l = 0, r = max_couples;

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        int minutes = dijkstra(0, n, mid);

        if (minutes <= max_minutes)
            l = mid;
        else
            r = mid;
    }

    return l;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph = vector<vector<pair<int, pair<int, int>>>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2, t, max_weight;
        cin >> v1 >> v2 >> t >> max_weight;

        v1--;
        v2--;
        max_weight = (max_weight - truck_weight) / couple_weight;

        graph[v1].push_back({v2, {t, max_weight}});
        graph[v2].push_back({v1, {t, max_weight}});
    }

    if (n == 1)
        cout << max_couples;
    else
        cout << find_optimum(n);

    return 0;
}
