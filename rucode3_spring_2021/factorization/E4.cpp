#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <functional>
#include <stack>
#include <iomanip>


#define pb push_back
#define pf push_front
#define FOR(n) for (int i = 0; i < n; i++)
#define FORj(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define tab cout << '\n'
#define fix(x) cout << fixed << setprecision(x);
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
istream& operator >> (istream& in, vector <int>& a) {
    for (auto& i : a) in >> i; return in;
}
ostream& operator << (ostream& out, vector <int>& a) {
    for (auto& i : a) out << i << " "; return out;
}
istream& operator >> (istream& in, vector <long long>& a) {
    for (auto& i : a) in >> i; return in;
}
ostream& operator << (ostream& out, vector <long long>& a) {
    for (auto& i : a) out << i << " "; return out;
}
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;
typedef pair <ll, ll> pll;
const int INF = 1e9 + 7;
const ll lINF = 1e18;
const int d8x[8] = { 1, 2, -1, -2, 1, 2, -1, -2 },
d8y[8] = { -2, -1, 2, 1, 2, 1, -2, -1 };
const int d4x[4] = { -1, 1, 0, 0 }, d4y[4] = { 0, 0, -1, 1 };
const int base = 1e9;
const int mxN = 2000010;
ld PI = acosl(-1.0);
void print(int x) { cerr << x << '\n'; }
void print(long x) { cerr << x << '\n'; }
void print(ll x) { cerr << x << '\n'; }
void print(unsigned x) { cerr << x << '\n'; }
void print(unsigned long x) { cerr << x << '\n'; }
void print(ull x) { cerr << x << '\n'; }
void print(float x) { cerr << x << '\n'; }
void print(double x) { cerr << x << '\n'; }
void print(ld x) { cerr << x << '\n'; }
void print(char x) { cerr << x << '\n'; }
void print(const char* x) { cerr << x << '\n'; }
void print(const string& x) { cerr << x << '\n'; }
void print(bool x) { cerr << (x ? "true\n" : "false\n"); }
double rtog(double r) { return r * 180 / PI; }
double gtor(double g) { return g * PI / 180; }
ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    if (n & 1) return (binpow(a, n - 1) * a);
    else { ll b = binpow(a, n / 2); return b * b; }
}






vector <ll> findPrimes(int n)
{
    vector <int> mind(n + 1);
    vector <ll> primes;
    for (int i = 1; i <= n; mind[i] = i, i++);
    for (ll x = 2; x <= n; x++)
    {
        if (mind[x] == x)
            primes.push_back(x);
        for (auto& p : primes)
        {
            if (x * p > n || mind[x] < p)
                break;
            mind[x * p] = p;
        }
    }
    return primes;
}


int main()
{
    fast;

    ll n;
    cin >> n;
    bool isPrime = true;
    vector <ll> primes = findPrimes(1e6);
    for (auto& p : primes)
        if (n != p && n % p == 0)
            isPrime = false;
    if (isPrime)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (ll d = 2; d * d <= n; d++)
        if (n % d == 0)
        {
            cout << d << " " << n / d;
            break;
        }

    return 0;
}

На вход 326155145533928057
Выход IMPOSSIBLE
Ответ 90411617 3607447321