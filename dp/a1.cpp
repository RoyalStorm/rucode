#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (auto i = 0; i < n; i++)
        std::cin >> v[i];

    std::vector<int> d(n);
    for (auto i = 0; i < n; i++) {
        d[i] = 1;
        for (auto j = 0; j < i; j++) {
            if (v[j] < v[i])
                d[i] = std::max(d[i], d[j] + 1);
        }
    }

    int res = d[0];
    for (auto i = 0; i < n; i++)
        res = std::max(res, d[i]);

    std::cout << res;

    return 0;
}
