#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> graph;

pair<int, vector<int>> bfs_01(int start, int n) {
    deque<int> deq;
    vector<int> dist(n, INT_MAX);
    vector<int> vertexes_history(n);

    deq.push_back(start);
    dist[start] = 0;
    vertexes_history[start] = -1;

    while (!deq.empty()) {
        int curr_v = deq.front();
        deq.pop_front();

        for (auto p : graph[curr_v]) {
            int to = p.first;
            int weight = p.second;

            if (weight + dist[curr_v] < dist[to]) {
                dist[to] = weight + dist[curr_v];

                if (weight == 0)
                    deq.push_front(to);
                else
                    deq.push_back(to);

                vertexes_history[to] = curr_v;
            }
        }
    }

    if (dist[n - 1] == INT_MAX)
        return {-1, vector<int>(n)};

    vector<int> path;
    int end = n - 1;
    while (end != -1) {
        path.push_back(end);
        end = vertexes_history[end];
    }

    reverse(path.begin(), path.end());

    return {dist[n - 1], path};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> whose_city(n);
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        whose_city[i] = --type;
    }

    graph = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        v1--;
        v2--;

        int weight;
        if (whose_city[v1] == whose_city[v2])
            weight = 0;
        else
            weight = 1;

        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }

    pair<int, vector<int>> res = bfs_01(0, n);

    if (res.first > -1) {
        cout << res.first << " " << res.second.size() << endl;
        for (auto el : res.second)
            cout << el + 1 << " ";
    } else
        cout << "impossible";

    return 0;
}
