#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v = vector<int>(n);
    multiset<int> set;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        
        if (i < k)
            set.insert(v[i]);
    }

    for (int i = 0; i < n - k + 1; i++) {
        cout << *set.begin() << '\n';

        if (i + k != n) {
            set.erase(set.find(v[i]));
            set.insert(v[i + k]);
        }
    }

    return 0;
}