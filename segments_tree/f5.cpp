#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

long long n;
vector<long long> a;
vector<long long> t;


long long func(long long a, long long b) {
    return a + b;
}

void build(long long v, long long l, long long r) {
    if (l == r - 1) {
        t[v] = a[l];
        return;
    }

    long long m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    t[v] = func(t[2 * v + 1], t[2 * v + 2]);
}

long long ask(long long v, long long l, long long r, long long askl, long long askr) {
    if (l >= askr || r <= askl)
        return 0;

    if (l >= askl && r <= askr)
        return t[v];

    long long m = (l + r) / 2;
    return func(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
}

void change(long long v, long long l, long long r, long long pos, long long val) {
    if (l == r - 1) {
        t[v] = val;
        return;
    }

    long long m = (l + r) / 2;

    if (pos < m)
        change(2 * v + 1, l, m, pos, val);
    else
        change(2 * v + 2, m, r, pos, val);

    t[v] = func(t[2 * v + 1], t[2 * v + 2]);
}

int main() {
    long long k;
    cin >> n >> k;

    a.resize(n);
    t.resize(4 * n);
    build(0, 0, n);

    for (auto i = 0; i < k; i++) {
        char action;
        cin >> action;

        if (action == 'A') {
            long long i, x;
            cin >> i >> x;
            change(0, 0, n, i - 1, x);
        }
        else {
            long long l, r;
            cin >> l >> r;
            cout << ask(0, 0, n, l - 1, r) << endl;
        }
    }

    return 0;
}