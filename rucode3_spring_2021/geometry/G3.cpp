#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>

#define ll long long
#define ld long double
#define vll vector<vector<ll>>
#define vd vector<ld>
#define vdd vector<vector<ld>>
#define vl vector<ll>
#define fi(a, n) for(ll i = (a); i < (n); ++i)
#define fj(a, n) for(ll j = (a); j < (n); ++j)

const ld EPS = 1e-9;
const ll mod = 1e9+7;

using namespace std;

struct point{
    ld x, y;
    point(){x = y = 0.0;}
    point(ld _x, ld _y): x(_x), y(_y){}
};

struct vec{
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y){}
};

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, ld s){
    return vec(v.x*s, v.y*s);
}
point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

ld dot(vec a, vec b){
    return a.x * b.x + a.y * b.y;
}
ld norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}

ld hy_pot(ld dx, ld dy){
    return sqrt(dx * dx + dy * dy);
}

ld dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

ld dist_to_line(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab)/ norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}
ld dist_to_segment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab)/ norm_sq(ab);
    if(u < 0.0){
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if(u > 1.0){
        return dist(p, b);
    }
    return dist_to_line(p, a, b, c);
}

ld area(vector<point> p){
    ld res = 0.0, x1, y1, x2, y2;
    x1 = p[0].x;
    y1 = p[0].y;
    fi(1, p.size()){
        x2 = p[i].x;
        y2 = p[i].y;

        res = res + (x1 + x2) * (y2 - y1);
        x1 = x2;
        y1 = y2;
//        x1 = p[i].x;x2 = p[i + 1].x;
//        y1 = p[i].y;y2 = p[i + 1].y;
//        res += (x1*y2 - x2 * y1);
//        res += x1 * (y2 - y1);

    }
    res = res + (p[0].x + x2) * (p[0].y - y2);
    return fabs(res)/ 2.0;
}

ld cross( vec a, vec b){
    return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
//    ll sz = p.size();
//    if(sz < 3){
//        return false;
//    }
//    bool isLeft = ccw(p[0], p[1], p[2]);
//    fi(1, sz-1){
//        if(ccw(p[i], p[i+1], p[(i+2) == sz ? 1: i + 2]) != isLeft)
//            return false;
//    }
//    return true;

bool isConvex(vector<point> &t){

    ll l, r;
    ll n = t.size();
    if(n < 3){
        return false;
    }
    bool isccw = ccw(t[n-1], t[0], t[1]);
    for(ll i = 1; i < n; ++i){
        l = (i - 1 + n) % n;
        r = (i + 1) % n;
        if(ccw(t[l], t[i], t[r]) != isccw){
            return false;
        }
    }
    return true;
}

bool Convex(vector<point> p)
{
    int i,j,k;
    int flag = 0;
    ld z;
    ll n = p.size();

    if (n < 3)
        return(0);

    for (i=0;i<n;i++) {
        j = (i + 1) % n;
        k = (i + 2) % n;
        z  = (p[j].x - p[i].x) * (p[k].y - p[j].y);
        z -= (p[j].y - p[i].y) * (p[k].x - p[j].x);
        if (z < 0)
            flag |= 1;
        else if (z > 0)
            flag |= 2;
        if (flag == 3)
            return(false);
    }
    if (flag != 0)
        return(true);
    else
        return(false);
}

//ld angle(point a, point o, point b){
//    vec oa = toVec(o, a), ob = toVec(o, b);
//    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
//}
//
vector<point> p;
//
//bool inPolygon(point pt){
//    if(p.size() == 0)
//        return false;
//    ld sum = 0;
//    fi(0, p.size() - 1){
//        if(ccw(pt, p[i], p[i + 1]))
//            sum += angle(p[i], pt, p[i + 1]);
//        else
//            sum -= angle(p[i], pt, p[i + 1]);
//
//    }
//    return fabs(fabs(sum) - 2 * M_PI) < EPS;
//}

struct ang{
    ld a, b;
};

bool operator < (const ang &p, const ang &q){
    if(p.b == 0 && q.b == 0)
        return p.a < q.a;
    return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

long long sq (point & a, point & b, point & c) {
    return a.x*1ll*(b.y-c.y) + b.x*1ll*(c.y-a.y) + c.x*1ll*(a.y-b.y);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    p.resize(n);
    ll zero_id = 0.0;
    fi(0, n){
        cin >> p[i].x >> p[i].y;
        if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
            zero_id = i;
    }
    point zero = p[zero_id];

    rotate (p.begin(), p.begin()+zero_id, p.end());
    p.erase (p.begin());
    --n;

    vector<ang> a (n);
    for (int i=0; i<n; ++i) {
        a[i].a = p[i].y - zero.y;
        a[i].b = p[i].x - zero.x;
        if (a[i].a == 0)
            a[i].b = a[i].b < 0 ? -1 : 1;
    }
    ll cnt = 0;
    fi(0, m){
        point q; // очередной запрос
        cin >> q.x >> q.y;
        bool in = false;
        if (q.x >= zero.x)
            if (q.x == zero.x && q.y == zero.y)
                in = true;
            else {
                ang my = { q.y-zero.y, q.x-zero.x };
                if (my.a == 0)
                    my.b = my.b < 0 ? -1 : 1;
                vector<ang>::iterator it = upper_bound (a.begin(), a.end(), my);
                if (it == a.end() && my.a == a[n-1].a && my.b == a[n-1].b)
                    it = a.end()-1;
                if (it != a.end() && it != a.begin()) {
                    int p1 = int (it - a.begin());
                    if (sq (p[p1], p[p1-1], q) <= 0)
                        in = true;
                }
            }
        if(in){
            ++cnt;
        }
    }
    
    if(cnt >= k){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }

//    cout<< fixed <<setprecision(20) << ans;
    return 0;
}













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
    if (n & 1) return binpow(a, n - 1) * a;
    else { ll b = binpow(a, n / 2); return b * b; }
}




struct vec {
    ld x, y;
};
vec operator + (vec a, vec b) {
    return vec{ a.x + b.x, a.y + b.y };
}
vec operator - (vec a, vec b) {
    return vec{ a.x - b.x, a.y - b.y };
}
vec operator / (vec a, ld k) {
    return vec{ a.x / k, a.y / k };
}
vec operator / (ld k, vec a) {
    return vec{ a.x / k, a.y / k };
}
bool operator == (vec a, vec b){
    return a.x == b.x && a.y == b.y;
}
ld vecmult(vec a, vec b) {
    return a.x * b.y - b.x * a.y;
}
ld scalmult(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}
ld veclen(vec a) {
    return hypotl(a.x, a.y);
}
ld sign(ld x) {
    return (x == 0 ? 0 : x < 0 ? -1 : 1);
}
bool parallel(vec a, vec b, vec c, vec d)
{
    return vecmult(a - b, c - d) == 0;
}
bool isPointOnSegment(vec p, vec a, vec b)
{
    return vecmult(p - a, p - b) == 0 && scalmult(p - a, p - b) <= 0;
}
bool isPointInAngle(vec p, vec a, vec b, vec c)
{
    return vecmult(c - b, p - b) >= 0 && vecmult(p - b, a - b) >= 0;
}
bool isPointInTriangle(vec p, vec a, vec b, vec c)
{
    return isPointInAngle(p, a, b, c) && isPointInAngle(p, b, c, a) && isPointInAngle(p, c, a, b);
}
ld getPointDistToRay(vec a, vec b, vec c)
{
    if (scalmult(b - c, b - a) > 0)
        return abs(vecmult(b - c, b - a) / veclen(b - c));
    else
        return veclen(a - b);
}
ld getPointDistToSegment(vec a, vec b, vec c)
{
    if (scalmult(b - c, b - a) > 0 && scalmult(c - b, c - a) > 0)
        return abs(vecmult(b - c, b - a) / veclen(b - c));
    else
        return min(veclen(a - b), veclen(a - c));
}
ld getTriangleArea(vec a, vec b, vec c)
{
    return abs(vecmult(a - b, a - c)) / 2.0;
}
ld getPolygonArea(vector <vec>& p, int n)
{
    ld ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += vecmult(p[i], p[i + 1]);
    ans += vecmult(p[n - 1], p[0]);
    return abs(ans) / 2;
}
bool isSegmentIntersect(vec p1, vec p2, vec p3, vec p4)
{
    if (parallel(p1, p2, p3, p4))
    {
        return isPointOnSegment(p1, p3, p4) || isPointOnSegment(p2, p3, p4) ||
            isPointOnSegment(p3, p1, p2) || isPointOnSegment(p4, p1, p2);
    }
    else
    {
        return sign(vecmult(p1 - p2, p1 - p4)) * sign(vecmult(p1 - p2, p1 - p3)) <= 0 &&
            sign(vecmult(p3 - p4, p3 - p1)) * sign(vecmult(p3 - p4, p3 - p2)) <= 0;
    }
}
ld getDistBetweenSegments(vec a, vec b, vec c, vec d)
{
    return 0;
}
bool isPolygonConvex(vector <vec>& p, int n)
{
    bool f  = (vecmult(p[0] - p[n - 1], p[1] - p[0]) <= 0);
    for (int i = 1; i < n - 1; i++)
        if ((vecmult(p[i] - p[i - 1], p[i + 1] - p[i]) <= 0) != f)
            return false;
    if ((vecmult(p[n - 1] - p[n - 2], p[0] - p[n - 1]) <= 0) != f)
        return false;
    return true;
}
bool isPointOnPolygon(vec p, vector <vec>& poly, int n)
{
    for (int i = 0; i < n - 1; i++)
        if (isPointOnSegment(p, poly[i], poly[i + 1]))
            return true;
    if (isPointOnSegment(p, poly[n - 1], poly[0]))
        return true;
    int intersect = 0, mx = -INF;
    for (int i = 0; i < n; i++)
        if (poly[i].x > mx)
            mx = poly[i].x;
    vec a = { mx + 1,  p.y + 1};
    for (int i = 0; i < n - 1; i++)
        if (isSegmentIntersect(p, a, poly[i], poly[i + 1]))
            intersect++;
    if (isSegmentIntersect(p, a, poly[n - 1], poly[0]))
        intersect++;
    return (intersect & 1);
}
bool isPointOnConvexPolygon(vec p, vector <vec>& poly, int n)
{
    if (!isPointInAngle(p, poly[n - 1], poly[0], poly[1]))
        return false;
    int l = 1, r = n - 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (vecmult(poly[0] - poly[mid], poly[0] - p) >= 0)
            l = mid;
        else
            r = mid;
    }
    return isPointInTriangle(p, poly[0], poly[l], poly[r]);
}
int main()
{
    fast;
    fix(12);


    int n, m, k, cnt = 0;
    cin >> n >> m >> k;
    vector <vec> poly(n);
    for (auto& i : poly)
        cin >> i.x >> i.y;
    while (m--)
    {
        vec p;
        cin >> p.x >> p.y;
        (isPointOnConvexPolygon(p, poly, n) ? cnt++ : 0);
    }
    cout << (cnt >= k ? "YES" : "NO");
    return 0;
}









#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T1, class T2> constexpr const auto _min(const T1& x, const T2& y) { return x < y ? x : y; } template <class T, class... Ts> constexpr auto _min(const T& x, const Ts&... xs) { return _min(x, _min(xs...)); }
template <class T1, class T2> constexpr const auto _max(const T1& x, const T2& y) { return x > y ? x : y; } template <class T, class... Ts> constexpr auto _max(const T& x, const Ts&... xs) { return _max(x, _max(xs...)); }

#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)

using uint = unsigned;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using pull = pair<ull, ull>;
template <class T> using vec = vector<T>;
template <class T> using vv = vec<vec<T>>;
template <class T> using vvv = vec<vv<T>>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fastio();

const int INF = 1e9;
const ll INF2 = 1e18;
const int MOD = 1e9 + 7;
const ull MOD2 = (1ULL << 61) - 1;
const int MAXN = 1e6 + 50;
const int N = 1e4 + 5;
const ld EPS = 1e-9;
const ld PI = 2.0L * acos(.0L);
const int P = 239;
const int P2 = 97;

struct Hash {
	ull operator()(ull x) const {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	ull operator()(const string& s) const {
		ull h = P2;
		for (const char c : s) {
			h = h * P + Hash()(c);
		}
		return h;
	}

	template <class T1, class T2>
	ull operator()(const pair<T1, T2>& a) const {
		ull h = P2;
		h = h * P + Hash()(a.first);
		h = h * P + Hash()(a.second);
		return h;
	}

	template <class T>
	inline static void unite(ull& h, const T& x) {
		h = h * P + Hash()(x);
	}
};

// 3x boost without second hash
struct PolyHash {
	static ull pows[MAXN];
	static ull pows2[MAXN];
	static int Index;
	vec<ull> h;
	vec<ull> h2;

	inline ull mulm(const ull& a, const ull& b) const {
		ull l1 = (uint)a, h1 = a >> 32, l2 = (uint)b, h2 = b >> 32;
		ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
		ull ret = (l & MOD2) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
		ret = (ret & MOD2) + (ret >> 61);
		ret = (ret & MOD2) + (ret >> 61);
		return ret - 1;
	}

	PolyHash(const string& s) {
		int n = s.size();
		while (Index <= n) {
			pows[Index] = pows[Index - 1] * P;
			pows2[Index] = mulm(pows2[Index - 1], P2);
			++Index;
		}
		h.resize(n);
		h2.resize(n);
		h[0] = s[0];
		h2[0] = s[0];
		for (int i = 1; i < n; ++i) {
			h[i] = h[i - 1] * P + s[i];
			h2[i] = mulm(h2[i - 1], P2) + s[i];
			if (h2[i] >= MOD2) h2[i] -= MOD2;
		}
	}

	auto operator()(const int l, const int r) const {
		ull Big = h[r], Small = 0;
		ll Big2 = h2[r], Small2 = 0;
		if (l > 0) {
			Small = h[l - 1] * pows[r - l + 1];
			Small2 = mulm(h2[l - 1], pows2[r - l + 1]);
		}
		//return Big - Small;
		return pair{Big - Small, (Big2 -= Small2) < 0 ? Big2 + MOD2 : Big2};
	}
};

ull PolyHash::pows[MAXN]{1};
ull PolyHash::pows2[MAXN]{1};
int PolyHash::Index = 1;

template <class T>
istream& operator >>(istream& in, vec<T>& a) {
	for(auto& i : a) in >> i;
	return in;
}

template <class T>
ostream& operator <<(ostream& out, vec<T> a) {
	for(const T& i : a) out << i << ' ';
	return out;
}

template <class T>
ostream& operator <<(ostream& out, vv<T> a) {
	for(const auto& i : a) {
		for(const T& j : i) out << j << ' ';
		out << '\n';
	}
	return out;
}

mt19937 _gen(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_real_distribution<ld> _uid(1e5, 1e9);

#define ff first
#define ss second
#define pb push_back
#define null nullptr
#define mp make_pair
#define rand _uid(_gen)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cerr << #x << " = " << x << '\n';
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define ford(i, n, d) for (int i = 0; i < n; i += d) 
#define rof(i, n) for (int i = n - 1; i >= 0; --i)
#define Time(start) (clock() - start) * 1.0L / CLOCKS_PER_SEC

struct pt {
	int x, y;
};

struct ang {
	int a, b;
};

bool operator < (const ang & p, const ang & q) {
	if (p.b == 0 && q.b == 0)
		return p.a < q.a;
	return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

long long sq (pt & a, pt & b, pt & c) {
	return a.x*1ll*(b.y-c.y) + b.x*1ll*(c.y-a.y) + c.x*1ll*(a.y-b.y);
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pt> p (n);
	int zero_id = 0;
	for (int i=0; i<n; ++i) {
		scanf ("%d%d", &p[i].x, &p[i].y);
		if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
			zero_id = i;
	}
	vec<pt> t(m);
	for(auto& i : t) cin >> i.x >> i.y;
	pt zero = p[zero_id];
	rotate (p.begin(), p.begin()+zero_id, p.end());
	p.erase (p.begin());
	--n;

	vector<ang> a (n);
	for (int i=0; i<n; ++i) {
		a[i].a = p[i].y - zero.y;
		a[i].b = p[i].x - zero.x;
		if (a[i].a == 0)
			a[i].b = a[i].b < 0 ? -1 : 1;
	}
	int cnt = 0;
	forn(i, m) {
		pt q = t[i]; // очередной запрос
		bool in = false;
		if (q.x >= zero.x)
			if (q.x == zero.x && q.y == zero.y)
				in = true;
			else {
				ang my = { q.y-zero.y, q.x-zero.x };
				if (my.a == 0)
					my.b = my.b < 0 ? -1 : 1;
				auto it = upper_bound (a.begin(), a.end(), my);
				if (it == a.end() && my.a == a[n-1].a && my.b == a[n-1].b)
					it = a.end()-1;
				if (it != a.end() && it != a.begin()) {
					int p1 = int (it - a.begin());
					if (sq (p[p1], p[p1-1], q) <= 0)
						in = true;
				}
			}
		cnt += in;
	}
	if (cnt >= k) cout << "YES";
	else cout << "NO";
}

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.setf(ios::fixed);
	cout.precision(16);
	#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	freopen("err.txt", "w", stderr);
	#endif
}

















#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(-1000000000, 1000000000);
struct pt {int x, y;};
struct ang {int a, b;};
bool operator < (const ang& p, const ang& q) {
	if (p.b == 0 && q.b == 0)
		return p.a < q.a;
	return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

ll sq(pt& a, pt& b, pt& c) {
	return a.x * 1ll * (b.y - c.y) + b.x * 1ll * (c.y - a.y) + c.x * 1ll * (a.y - b.y);
}
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k, res = 0;
	cin >> n >> m >> k;
	vector<pt> p(n);
	int zero_id = 0;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
		if (p[i].x < p[zero_id].x || p[i].x == p[zero_id].x && p[i].y < p[zero_id].y)
			zero_id = i;
	}
	pt zero = p[zero_id];
	rotate(p.begin(), p.begin() + zero_id, p.end());
	p.erase(p.begin());
	--n;

	vector<ang> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].a = p[i].y - zero.y;
		a[i].b = p[i].x - zero.x;
		if (a[i].a == 0)
			a[i].b = a[i].b < 0 ? -1 : 1;
	}

	while (m--) {
		pt q;
		int in = 0;
		cin >> q.x >> q.y;
		if (q.x >= zero.x) {
			if (q.x == zero.x && q.y == zero.y)
				in = 1;
			else {
				ang my = { q.y - zero.y, q.x - zero.x };
				if (my.a == 0)
					my.b = my.b < 0 ? -1 : 1;
				vector<ang>::iterator it = upper_bound(a.begin(), a.end(), my);
				if (it == a.end() && my.a == a[n - 1].a && my.b == a[n - 1].b)
					it = a.end() - 1;
				if (it != a.end() && it != a.begin()) {
					int p1 = int(it - a.begin());
					if (sq(p[p1], p[p1 - 1], q) <= 0)
						in = 1;
				}
			}
		}
		res += in;
	}
	cout << (res >= k ? "YES" : "NO");
}