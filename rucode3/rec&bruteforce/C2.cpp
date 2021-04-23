#include <bits/stdc++.h>

#define int int64_t

using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    int n;
    cin >> n;
    int p[n], f[n + 1];
    bool used[n + 1];
    memset(used, false, sizeof used);
    for(auto &i: p)
        cin >> i;
    f[1] = f[0] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = (f[i - 1] * i) % mod;
    int cur = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 1; j < p[i]; j++)
            cnt += !used[j];
        cur += cnt * f[n - i - 1] % mod;
        cur %= mod;
        used[p[i]] = true;
    }
    cout << (cur + 1) % mod;
}