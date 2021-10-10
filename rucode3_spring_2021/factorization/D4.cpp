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

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
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
        cout << ans << '\n';
    }
}








#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <iomanip>
#define pii pair<int, int>

using namespace std;
const int INF = 1e9;
typedef long long ll;

ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    while (cin >> x)
        cout << phi(x) << '\n';

}