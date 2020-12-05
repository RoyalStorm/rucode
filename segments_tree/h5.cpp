#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> a;
vector<int> t;


int func(int a, int b) {
    return a + b;
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

int ask(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl)
        return 0;

    if (l >= askl && r <= askr)
        return t[v];

    int m = (l + r) / 2;
    return func(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
}

void change(int v, int l, int r, int pos, int val) {
    if (l == r - 1) {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if (pos < m)
        change(2 * v + 1, l, m, pos, val);
    else
        change(2 * v + 2, m, r, pos, val);

    t[v] = func(t[2 * v + 1], t[2 * v + 2]);
}

int main() {
    int n;
    cin >> n;

    a.resize(n);
    t.resize(4 * n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (i % 2 == 0)
            a[i] = val;
        else
            a[i] = -val;
    }

    build(0, 0, n);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int action;
        cin >> action;

        if (action == 0) {
            int i, j;
            cin >> i >> j;

            if ((i - 1) % 2 != 0)
                j = -j;

            change(0, 0, n, i - 1, j);
        }
        else {
            int l, r;
            cin >> l >> r;

            int res = ask(0, 0, n, l - 1, r);

            if ((l - 1) % 2 != 0)
                res = -res;

            cout << res << endl;
        }
    }

    return 0;
}