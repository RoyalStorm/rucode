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

int binpow(int x, int y, int mod){
    if(y == 0)
        return 1;
    if(y & 1)
        return binpow(x, y - 1, mod) * x % mod;
    int z = binpow(x, y>>1, mod);
    return z * z % mod;
}

vector<int> factorize(int n){
    int s = ceil(sqrt(n));
    vector<int> factors;
    for (int i = 2; i <= s; i++) {
        while (n % i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }
    if (n != 1)
        factors.push_back(n);
    return factors;
}

bool check(int root, int n, int f, vector<int> &factors){
    for(auto i: factors)
        if(binpow(root, f / i, n) == 1)
            return false;
    return true;

}

int root(int p){
    int g = 1, f = fi(p);
    vector<int> factors = factorize(f);
    while(!check(g, p, f, factors))
        g++;
    return g;
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int p;
    while (cin >> p)
        cout << root(p) << '\n';
}