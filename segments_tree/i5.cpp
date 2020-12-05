#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define max_m 16777216

vector<int> array;
vector<int> t;


int func(int a, int b) {
    return a + b;
}

int ask(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl)
        return 0;

    if (l >= askl && r <= askr)
        return t[v];

    int m = (l + r) / 2;
    return func(ask(2 * v + 1, l, m, askl, askr), ask(2 * v + 2, m, r, askl, askr));
}

void change(int v, int l, int r, int pos) {
    if (l == r - 1) {
        t[v]++;
        return;
    }

    int m = (l + r) / 2;

    if (pos < m)
        change(2 * v + 1, l, m, pos);
    else
        change(2 * v + 2, m, r, pos);

    t[v] = func(t[2 * v + 1], t[2 * v + 2]);
}

unsigned int cur = 0;

unsigned int nextRand24(int a, int b) {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    cin >> a >> b;

    array.resize(n);
    t.resize(max_m);

    for (int i = 0; i < n; i++)
        array[i] = ((nextRand24(a, b) % m) + m) % m;

    vector<int> tmp = array;
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

    for (int i = 0; i < n; i++)
        array[i] = lower_bound(tmp.begin(), tmp.end(), array[i]) - tmp.begin();

    long res = 0;
    for (auto &el : array) {
        res += ask(0, 0, n, el + 1, n);
        change(0, 0, n, el);
    }

    cout << res;

    return 0;
}