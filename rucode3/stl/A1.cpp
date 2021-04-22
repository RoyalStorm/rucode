#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v = vector<int>(2 * n);

    for (int i = 0; i < n; ++i)
        cin >> v[2 * i] >> v[2 * i + 1];

    vector<int> compressed_coords = v;
    sort(compressed_coords.begin(), compressed_coords.end());
    compressed_coords.resize(unique(compressed_coords.begin(), compressed_coords.end()) - compressed_coords.begin());

    for (int i = 0; i < n; ++i) {
        cout << lower_bound(compressed_coords.begin(), compressed_coords.end(), v[2 * i]) - compressed_coords.begin() << ' ';
        cout << lower_bound(compressed_coords.begin(), compressed_coords.end(), v[2 * i + 1]) - compressed_coords.begin();
        cout << '\n';
    }

    return 0;
}