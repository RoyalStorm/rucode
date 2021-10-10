#include <bits/stdc++.h>

#define double long double

using namespace std;

struct point{
    double x, y;
    point(){}
    point(double f, double s){
        x = f, y = s;
    }
};

struct line{
    point f, s;
    double a, b, c;
    line(){}
    line(double fx, double fy, double sx, double sy){
        f.x = fx, f.y = fy, s.x = sx, s.y = sy;
        a = fy - sy;
        b = sx - fx;
        c = -a * fx - b * fy;
    }
};

double dist(point &a, point &b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(line &a, point &b){
    return abs(a.a * b.x + a.b * b.y + a.c) / sqrt(a.a * a.a + a.b * a.b);
}

double cos(line a, point b){
    b.x -= a.f.x;
    b.y -= a.f.y;
    a.s.x -= a.f.x;
    a.s.y -= a.f.y;
    a.f.x = a.f.y = 0;
    return (a.s.x * b.x + a.s.y * b.y) / dist(a.f, a.s) / dist(a.f, b);
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    double xf, yf, xs, ys;
    cin >> xf >> yf;
    point a(xf, yf);
    cin >> xf >> yf >> xs >> ys;
    line l(xf, yf, xs, ys);
    if(cos(l, a) >= 0)
        cout << dist(l, a);
    else
        cout << dist(a, l.f);
}







#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f first
#define s second
#define bust ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = INT_MAX;
const int mod = 1e9 + 7;

ll vec_product (ll ax, ll ay, ll bx, ll by)
{
    return ax * by - bx * ay;
}

ll scal_product (ll ax, ll ay, ll bx, ll by)
{
    return ax * bx + by * ay;
}

long double dist_from_point_to_prom (ll xa, ll ya, ll xb, ll yb, ll xc, ll yc)
{
    ll ax = (xa - xb), ay = (ya - yb), bx = (xc - xb), by = (yc - yb);
    if (scal_product(ax, ay, bx, by) <= 0)
        return sqrt(ax * ax + ay * ay);
    else
    {
        ll A = by, B = -bx, C = -(A * xb + B * yb);
        return abs(A * xa + B * ya + C) / sqrt(A * A + B * B);
    }
}

void solve ()
{
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    cout << fixed << setprecision(6) << dist_from_point_to_prom(xa, ya, xb, yb, xc, yc) << "\n";
}

int main()
{
    bust
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while (t--)
        solve();
	return 0;
}