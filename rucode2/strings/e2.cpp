#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_func(vector<int> &s) {
    vector<int> pf(s.size());

    int k = 0;
    for (int i = 1; i < s.size(); i++) {
        while (k > 0 && s[k] != s[i])
            k = pf[k - 1];

        if (s[k] == s[i])
            k++;

        pf[i] = k;
    }

    return pf;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> s(2 * n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        s[i] = val;
        s[2 * n - i - 1] = val;
    }

    auto pf = prefix_func(s);

    int i = pf[2 * n - 1];
    while (i > n)
        i = pf[i - 1];

    vector<int> res;
    while (i) {
        if (i % 2 == 0)
            res.push_back(n - i / 2);

        i = pf[i - 1];
    }
    res.push_back(n);

    for (auto &el : res)
        cout << el << " ";

    return 0;
}
