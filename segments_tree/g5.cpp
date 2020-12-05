#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <climits>

using namespace std;

const int n = 100005;
vector<int> a(n);
vector<int> t_max(n * 4, INT_MIN);
vector<int> t_min(n * 4, INT_MAX);

inline int func_max(int a, int b) {
    return max(a, b);
}

inline int func_min(int a, int b) {
    return min(a, b);
}

void build(long long v, long long l, long long r, string action) {
    if (l == r - 1) {
        if (action == "max")
            t_max[v] = a[l];
        else
            t_min[v] = a[l];

        return;
    }

    long long m = (l + r) / 2;

    if (action == "max") {
        build(2 * v + 1, l, m, "max");
        build(2 * v + 2, m, r, "max");

        t_max[v] = func_max(t_max[2 * v + 1], t_max[2 * v + 2]);
    }
    else {
        build(2 * v + 1, l, m, "min");
        build(2 * v + 2, m, r, "min");

        t_min[v] = func_min(t_min[2 * v + 1], t_min[2 * v + 2]);
    }
}

int ask(long long v, long long l, long long r, long long askl, long long askr, string action) {
    if (l >= askr || r <= askl) {
        if (action == "max")
            return INT_MIN;
        else
            return INT_MAX;
    }

    if (l >= askl && r <= askr) {
        if (action == "max")
            return t_max[v];
        else
            return t_min[v];
    }

    long long m = (l + r) / 2;

    if (action == "max")
        return func_max(ask(2 * v + 1, l, m, askl, askr, "max"), ask(2 * v + 2, m, r, askl, askr, "max"));
    else
        return func_min(ask(2 * v + 1, l, m, askl, askr, "min"), ask(2 * v + 2, m, r, askl, askr, "min"));
}

void change(long long v, long long l, long long r, long long pos, long long val) {
    if (l == r - 1) {
        t_max[v] = val;
        t_min[v] = val;
        return;
    }

    long long m = (l + r) / 2;

    if (pos < m)
        change(2 * v + 1, l, m, pos, val);
    else
        change(2 * v + 2, m, r, pos, val);

    t_max[v] = func_max(t_max[2 * v + 1], t_max[2 * v + 2]);
    t_min[v] = func_min(t_min[2 * v + 1], t_min[2 * v + 2]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (long long i = 1; i < n; i++)
        a[i - 1] = i * i % 12345 + i * i * i % 23456;;

    build(0, 0, n, "max");
    build(0, 0, n, "min");

    long long k;
    cin >> k;

    for (auto i = 0; i < k; i++) {
        long long x, y;
        cin >> x >> y;

        if (x < 0)
            change(0, 0, n, abs(x) - 1, y);
        else
            cout << ask(0, 0, n, x - 1, y, "max") - ask(0, 0, n, x - 1, y, "min") << endl;
    }

    return 0;
}