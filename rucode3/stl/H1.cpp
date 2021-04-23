#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector <pair <int, int> > p(n);
    vector <int> a(n - 1);
    for(int i = 0; i < n; i++)
        cin >> p[i].first, p[i].second = i;
    vector<int> h(n);
    for(auto &i: a)
        cin >> i;
    int cnt = 0;
    sort(p.begin(), p.end());
    do{
        bool can = true;
        for(int i = 0; i < n - 1; i++)
            if(p[i].first + p[i + 1].first > a[i])
                can = false;
        cnt += can;
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt;
}