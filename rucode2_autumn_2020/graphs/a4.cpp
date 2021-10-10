#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> field;
vector<vector<int>> dist;
vector<vector<bool>> used;
queue<pair<int, int>> queue_v;

void check(int i, int j) {
    // Check left side
    if ((j != 0) && (!used[i][j - 1] && (field[i][j - 1] != 1))) {
        dist[i][j - 1] = dist[i][j] + 1;
        used[i][j - 1] = true;
        queue_v.push({i, j - 1});
    }

    // Check rights side
    if ((j != m - 1) && (!used[i][j + 1]) && (field[i][j + 1] != 1)) {
        dist[i][j + 1] = dist[i][j] + 1;
        used[i][j + 1] = true;
        queue_v.push({i, j + 1});
    }

    // Check upper side
    if ((i != 0) && (!used[i - 1][j]) && (field[i - 1][j] != 1)) {
        dist[i - 1][j] = dist[i][j] + 1;
        used[i - 1][j] = true;
        queue_v.push({i - 1, j});
    }

    // Check down side
    if ((i != n - 1) && (!used[i + 1][j]) && (field[i + 1][j] != 1)) {
        dist[i + 1][j] = dist[i][j] + 1;
        used[i + 1][j] = true;
        queue_v.push({i + 1, j});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    field = vector<vector<int>>(n, vector<int>(m, 0));
    dist = vector<vector<int>>(n, vector<int>(m, -1));
    used = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;

    dist[start_y - 1][start_x - 1] = 0;
    used[start_y - 1][start_x - 1] = true;

    queue_v.push({start_y - 1, start_x - 1});

    while (!queue_v.empty()) {
        pair<int, int> position = queue_v.front();
        queue_v.pop();

        check(position.first, position.second);
    }

    cout << dist[end_y - 1][end_x - 1];

    return 0;
}