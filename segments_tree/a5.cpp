#include <iostream>
#include <vector>

using namespace std;

#define mod_30 1073741824
#define mod_16 65536

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, x, y, a, m, z, t, b;
    cin >> n >> x >> y >> a;
    cin >> m >> z >> t >> b;

    if (m == 0) {
        cout << 0;

        return 0;
    }

    vector<int> A(n);
    vector<int> B(2 * m);
    vector<int> C(2 * m);
    A[0] = a;
    B[0] = b;
    C[0] = B[0] % n;

    for (int i = 1; i < 2 * m; i++) {
        if (i < n)
            A[i] = (x * A[i - 1] + y) % mod_16;

        B[i] = (((z * B[i - 1] + t) % mod_30) + mod_30) % mod_30;
        C[i] = B[i] % n;
    }

    long res = 0;
    vector<long> pref(n);
    for (int i = 0; i < n; i++) {
        pref[i] = A[i];
        if (i > 0)
            pref[i] += pref[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int l = min(C[2 * i], C[2 * i + 1]);
        int r = max(C[2 * i], C[2 * i + 1]);

        res += pref[r] - (l == 0 ? 0 : pref[l - 1]);
    }

    cout << res << endl;

    return 0;
}