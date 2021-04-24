#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#include <queue>
#include <ctime>
using namespace std;

#define ll long long
struct point
{
	ll x, y;
	point(ll a = 0, ll b = 0) {
		x = a, y = b;
	}
	point(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
	double get_l() {
		return sqrt(x * x + y * y);
	}
};
ll operator *(point v1, point v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
ll operator &(point v1, point v2) {
	return v1.x * v2.y - v1.y * v2.x;
}

double dist(point p, point seg1, point seg2) {
	point v1(seg1, seg2), v2(seg1, p), v3(seg2, seg1), v4(seg2, p);
	if (v1 * v2 <= 0) return v2.get_l();
	if (v3 * v4 <= 0) return v4.get_l();
	return  (double)abs((v2 & v4)) / v1.get_l();
}

ll orintation(point p, point seg1, point seg2) {
	point v1 = point(seg1, seg2), v2 = point(seg1, p);
	return ((v1 & v2) == 0) ? 0 : (v1 & v2) / abs(v1 & v2);
}

bool PointOnSeg(point p, point seg1, point seg2) {
	return ((point(seg1, seg2) & point(seg1, p)) == 0 && point(seg1, p).get_l() + point(seg2, p).get_l() == point(seg1, seg2).get_l());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, c = 0;
	cin >> n;
	point s;
	cin >> s.x >> s.y;
	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < n; i++) {
		if (PointOnSeg(s, a[i], a[(i + 1) % n])) {
			cout << "YES\n";
			return 0;
		}
		if (a[i].y == a[(i + 1) % n].y) {
			continue;
		}
		point v = a[i], u = a[(i + 1) % n];
		if (v.y < u.y)swap(v, u);
		if (s.y >= u.y && s.y < v.y && (point(u,v) & point(u,s)) >= 0) {
			c++;
		}
	}
	if (c % 2) {
		cout << "YES\n";
	}
	else cout << "NO\n";
	return 0;

}




import math
a, x0, y0 = map(int, input().split())
b = []
ans = 0
for i in range(a):
    x, y = map(int, input().split())
    b.append(x)
    b.append(y)
b.append(b[0])
b.append(b[1])
a1 = 0
b1 = 1
c1 = -y0
for j in range(0, len(b) - 2, 2):
    x1 = b[j]
    y1 = b[j + 1]
    x2 = b[j + 2]
    y2 = b[j + 3]
    vec_AO_x = x1 - x0
    vec_AO_y = y1 - y0
    vec_BO_x = x2 - x0
    vec_BO_y = y2 - y0
    scal = vec_AO_x * vec_BO_x + vec_AO_y * vec_BO_y
    coso = vec_AO_y * vec_BO_x - vec_AO_x * vec_BO_y
    k = math.atan2(coso, scal)
    ans += k
if ans == 0:
    print('NO')
else:
    print('YES')










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
int main()
{
    fast;
    fix(12);


    int n;
    vec a;
    cin >> n >> a.x >> a.y;
    vector <vec> p(n);
    for (auto& i : p)
        cin >> i.x >> i.y;
    cout << (isPointOnPolygon(a, p, n) ? "YES" : "NO");
    return 0;
}