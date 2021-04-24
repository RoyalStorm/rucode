#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int binpow(int x, int y){
    if(y == 0)
        return 1;
    if(y & 1)
        return binpow(x, y - 1) * x;
    int z = binpow(x, y>>1);
    return z * z;
}

int binpow(int x, int y, int mod){
    if(y == 0)
        return 1;
    if(y & 1)
        return binpow(x, y - 1, mod) * x % mod;
    int z = binpow(x, y>>1, mod);
    return z * z % mod;
}

int fi(int n){
    int s = ceil(sqrt(n)), ans = 1;
    for (int i = 2; i <= s; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt > 0)
            ans *= (binpow(i, cnt) - binpow(i, cnt - 1));
    }
    if (n != 1)
        ans *= (n - 1);
    return ans;
}

int inverse_element(int x, int mod){
    return binpow(x, fi(mod) - 1, mod);
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int c0 = m * inverse_element(m, n);
    int c1 = n * inverse_element(n, m);
    cout << (c0 * a + c1 * b) % (n * m);
}