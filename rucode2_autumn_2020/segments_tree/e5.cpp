#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<pair<int, int>> a;
vector<pair<int, int>> t;

ostream& operator <<(ostream& out, const pair<int, int>& pair) {
    out << pair.first << " " << pair.second;
    return out;
}

pair<int, int> func(pair<int, int> a, pair<int, int> b) {
    pair<int, int> res;
    int max_el = max(a.first, b.first);

    if (max_el == a.first)
        return a;
    else
        return b;
}

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    t[v] = func(t[2 * v + 1], t[2 * v + 2]);
}

pair<int, int> ask(int v, int l, int r, int askl , int askr) {
    if (l >= askr || r <= askl)
        return pair<int, int>(INT_MIN, -1);

    if (l >= askl && r <= askr)
        return t[v];

    int m = (l + r) / 2;
    return func(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
}

int main() {
    int n;
    cin >> n;

    a.resize(n);
    for (auto i = 0; i < n; i++) {
        int el;
        cin >> el;
        a[i].first = el;
        a[i].second = i;
    }

    t.resize(4 * n);
    build(0, 0, n);

    int k;
    cin >> k;
    for (auto i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        pair<int, int> res = ask(0, 0, n, l - 1, r);
        cout << res.first << " " << res.second + 1 << endl;
    }

    return 0;
}