#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 1;
ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    ll a, b;
    cin >> a >> b;

    bool prime[MAXN], ans[MAXN];
    memset(prime, true, MAXN);
    memset(ans, true, MAXN);
    prime[0] = prime[1] = false;

    ll mmax = MAXN - 1;
    for (ll i = 2; i <= mmax; ++i) {
        if (prime[i]) {
            ll r = a % i;
            r = (i - r) % i; 

            if (a + r > i && r < MAXN)  
                ans[r] = false;

            if (i + r < MAXN && a + r + i > i)
                ans[i + r] = false;
            for (ll j = 2 * i; j <= mmax; j += i) {
                prime[j] = false;
                if (a <= j && j - a < MAXN)
                    ans[j - a] = false;
                if (j + r < MAXN) {
                    ans[j + r] = false;
                }
            }
        }
    }
    for (ll i = 0; i <= b - a; ++i) {
        if (ans[i] && a + i >= 2)
            cout << a + i << ' ';
    }
}














#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 1e6 + 1;

vector < ll > prime;
vector < bool > resheto (N, true);

void solve ()
{
    for (ll i = 2; i < N; ++i)
    {
        if (resheto[i])
        {
            for (ll j = i + i; j < N; j += i)
                resheto[j] = false;
        }
        if (resheto[i])
            prime.push_back(i);
    }
    resheto[0] = false;
    resheto[1] = false;
    ll a, b;
    cin >> a >> b;
    if (a == 1ll)
        a = 2ll;
    int n = b - a + 1;
    vector < bool > new_resheto(n, true);
    for (int i = 0; i < prime.size(); ++i)
    {
        if (prime[i] > b) break ;
        ll j;

        if (a % prime[i] == 0)
        {
            j = prime[i];
            if (a != prime[i])
                j = 0;
        }
        else
            j = a / prime[i] * prime[i] + prime[i] - a;

        for (; j < new_resheto.size(); j += prime[i])
            if (j + a != prime[i]) new_resheto[j] = false ;
    }
    for (int i = 0; i < n; ++i)
        if (new_resheto[i]) cout << a + i << " ";
}

int main()
{
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while (t--)
        solve();
	return 0;
}