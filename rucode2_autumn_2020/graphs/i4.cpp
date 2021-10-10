#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<pair<int, pair<int, int>>>> graph;

int dijkstra(int s, int f, int n) {
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> queue;

    queue.insert({s, 0});
    dist[s] = 0;

    while (!queue.empty()) {
        int cur_v = queue.begin()->first;
        int distance = queue.begin()->second;
        queue.erase({cur_v, distance});

        sort(graph[cur_v].begin(), graph[cur_v].end(),
             [](pair<int, pair<int, int>> &left, pair<int, pair<int, int>> &right) {
                 return left.second.first > left.second.second;
             });

        for (auto p : graph[cur_v]) {
            int to = p.first;
            int start_time = p.second.first;
            int end_time = p.second.second;

            int weight = end_time- dist[cur_v];

            if (start_time < dist[cur_v] || dist[cur_v] + weight >= dist[to])
                continue;

            queue.erase({to, dist[to]});
            queue.insert({to, dist[cur_v] + weight});
            dist[to] = dist[cur_v] + weight;
        }
    }

    if (dist[f] == INT_MAX)
        return -1;
    else
        return dist[f];
}

int main() {
    int n, d, v, r;

    cin >> n;
    cin >> d >> v;
    cin >> r;

    d--;
    v--;

    graph = vector<vector<pair<int, pair<int, int>>>>(n);
    for (int i = 0; i < r; i++) {
        int v1, t1, v2, t2;
        cin >> v1 >> t1 >> v2 >> t2;
        v1--;
        v2--;

        graph[v1].push_back({v2, {t1, t2}});
    }

    cout << dijkstra(d, v, n);

    return 0;
}
