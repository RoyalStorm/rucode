#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e9) + 15;

#define pb push_back
#define fi first
#define se second
//using namespace __gnu_pbds;
//typedef tree <int, null_type, less_equal <int> , rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define sz(x) (int)x.size()
ll time() {return chrono::system_clock().now().time_since_epoch().count();}
mt19937 rnd(time());

const double PI = acos(-1);
const double PPI = 2 * PI;

ll phi(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }

    if (n > 1)
        res -= res / n;

    return res;
}

ll bp(ll a, ll n, ll mod)
{
    ll res = 1;

    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;

        n >>= 1;
    }

    return res;
}

ll inv_prime(ll x, ll mod)
{
    return bp(x, max(0ll, mod - 2), mod);
}

ll inv(ll x, ll mod)
{
    return bp(x, max(0ll, phi(mod) - 1), mod);
}


//void solve(ll m, ll a, ll b)
//{
//
//}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef _LOCAL_
        system("color a");
    #endif // _LOCAL_


    int t = 1;

    ll m, a, b;

    while (cin>>m>>a>>b)
    {
        a %= m; b %= m;

        ll n = sqrt(m) + 1;

        ll an = 1;
        for (ll i = 0; i < n; i++)
            an = (an * a) % m;

        unordered_map<ll, ll> ex;

        for (ll i = 0, cr = b; i <= n; i++)
        {
            ex[cr] = i;
            cr = (cr * a) % m;
        }

        bool fnd = false;

        for (ll i = 1, cr = 1; i <= n; i++)
        {
            cr = (cr * an) % m;
            if (ex.count(cr))
            {
                ll ans = i * n - ex[cr];
                cout << ans << '\n';
                fnd = true;
                break;
            }
        }

        if (!fnd)
            cout << "no solution" << '\n';
    }
}