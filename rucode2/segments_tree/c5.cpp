#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int cur = 0;

unsigned int nextRand24(int a_, int b_) {
    cur = cur * a_ + b_;
    return cur >> 8;
}

unsigned int nextRand32(int a_, int b_) {
    unsigned int a = nextRand24(a_, b_), b = nextRand24(a_, b_);
    return (a << 8) ^ b;
}

int main() {
    int n, q, a, b;
    cin >> n >> q;
    cin >> a >> b;

    vector<pair<long long, long long>> array(n);
    vector<pair<long long, long long>> ask(q);

    for (int i = 0; i < n; i++) {
        long long value = nextRand32(a, b), x = nextRand32(a, b);
        array[i] = make_pair(x, value);
    }

    for (int i = 0; i < n; i++) {
        long long l = nextRand32(a, b), r = nextRand24(a, b);

        if (l > r)
            swap(l, r);

        ask[i] = make_pair(l, r);
    }

    vector<pair<long long, long long>> tmp = array;
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

    /*for (int i = 0; i < n; i++)
        array[i] = lower_bound(tmp.begin(), tmp.end(), array[i]) - tmp.begin();*/

/*
5 5
13 239
*/

    return 0;
}
