#include <iostream>
#include <vector>
#include <set>

using namespace std;

std::vector<bool> used;
std::vector<std::set<int>> graph;

void dfs(int v) {
    used[v] = true;

    for (auto& u : graph[v]) {
        if (used[u])
            continue;

        dfs(u);
    }
}

int main() {
    int n;
    cin >> n;

    used = std::vector<bool>((n > 0) ? n : 1, false);
    graph = std::vector<std::set<int>>((n > 0) ? n : 1);

    for (int i = 0; i < n; i++) {
        int pig;
        cin >> pig;

        graph[pig - 1].insert(i);
        graph[i].insert(pig - 1);
    }

    int components_counter = 0;
    for (int i = 0; i < used.size(); i++) {
        if (used[i])
            continue;

        dfs(i);
        components_counter++;
    }

    cout << components_counter;

    return 0;
}
