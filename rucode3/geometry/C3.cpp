#include <bits/stdc++.h>

#define double long double
#define int int64_t

using namespace std;

struct point{
    int x, y;
    point(){}
    point(int f, int s){
        x = f, y = s;
    }
};

struct line{
    point f, s;
    int a, b, c;
    line(){}
    line(point i, point j){
        f = i;
        s = j;
        a = f.y - s.y;
        b = s.x - f.x;
        c = -a * f.x - b * f.y;
    }
    line(int fx, int fy, int sx, int sy){
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
    return (double)abs(a.a * b.x + a.b * b.y + a.c) / sqrt(a.a * a.a + a.b * a.b);
}

double cos(line a, point b){
    b.x -= a.f.x;
    b.y -= a.f.y;
    a.s.x -= a.f.x;
    a.s.y -= a.f.y;
    a.f.x = a.f.y = 0;
    return (double)(a.s.x * b.x + a.s.y * b.y) / dist(a.f, a.s) / dist(a.f, b);
}

double dist_seg(line l, point a){
    if(cos(l, a) >= 0 && cos(line(l.s, l.f), a) >= 0)
        return dist(l, a);
    else
        return min(dist(a, l.f), dist(a, l.s));
}

int area (point a, point b, point c) {
    return (double)((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

bool intersect_1 (double a, double b, double c, double d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) <= min(b,d);
}

bool intersect (point a, point b, point c, point d) {
    return intersect_1 (a.x, b.x, c.x, d.x)
           && intersect_1 (a.y, b.y, c.y, d.y)
           && area(a,b,c) * area(a,b,d) <= 0
           && area(c,d,a) * area(c,d,b) <= 0;
}

int32_t main() {
    cout.setf(ios::fixed);
    cout.precision(9);
    ios::sync_with_stdio(false);
    int fx, fy, sx, sy;
    cin >> fx >> fy >> sx >> sy;
    line a(fx, fy, sx, sy);
    cin >> fx >> fy >> sx >> sy;
    line b(fx, fy, sx, sy);
    if(intersect(a.f, a.s, b.f, b.s))
        cout << 0;
    else
        cout << min({dist_seg(a, b.f), dist_seg(a, b.s), dist_seg(b, a.f), dist_seg(b, a.s)});
}//lol





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

int orintation(point p, point seg1, point seg2) {
	point v1 = point(seg1, seg2), v2 = point(seg1, p);
	return ((v1 & v2) == 0)? 0 :(v1 & v2) / abs(v1 & v2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	if (orintation(c, a, b) != orintation(d,a,b) && orintation (a,c,d) != orintation(b,c,d)) {
		cout << 0 << "\n";
		return 0;
	}
	cout << fixed << setprecision(15) << min(dist(c, a, b), min(dist(d, a, b),min(dist(a,c,d),dist(b,c,d)))) << "\n";

	return 0;

}






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

double ras(double x1, double y1, double x2, double y2, double x3, double y3){
    double k,d;
    if(x1==x2){ //Если отрезок вертикальный - меняем местами координаты каждой точки.
        swap(x1, y1);
        swap(x2, y2);
        swap(x3, y3);
    }
    k=(y1-y2)/(x1-x2);//Ищем коэффициенты уравнения прямой, которому принадлежит данный отрезок.
    d=y1-k*x1;
    double xz=(x3*x2-x3*x1+y2*y3-y1*y3+y1*d-y2*d)/(k*y2-k*y1+x2-x1);
    double dl=-1;
    if((xz<=x2&&xz>=x1)||(xz<=x1&&xz>=x2)) dl=sqrt((x3-xz)*(x3-xz)+(y3-xz*k-d)*(y3-xz*k-d));//Проверим лежит ли основание высоты на отрезке.
    return dl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double xa, xb, ya, yb, xc, xd, yc, yd, dl, dl1, dl2, dl3, dl4, min=-1,o,o1,o2,t=-2,s=-2;
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
    o=(xb-xa)*(-yd+yc)-(yb-ya)*(-xd+xc);
    o1=(xb-xa)*(yc-ya)-(yb-ya)*(xc-xa);
    o2=(-yd+yc)*(xc-xa)-(-xd+xc)*(yc-ya);
    if(o!=0){
        t=o1/o;
        s=o2/o;
    }
    if((t>=0&&s>=0)&&(t<=1&&s<=1))min=0;//Проверим пересекаются ли отрезки.
    else{
        //Найдём наименьшую высоту опущенную из конца одного отрезка на другой.
        dl1=ras(xa,ya,xb,yb,xc,yc);
        min=dl1;
        dl2=ras(xa,ya,xb,yb,xd,yd);
        if((dl2<min&&dl2!=-1)||min==-1)min=dl2;
        dl3=ras(xc,yc,xd,yd,xa,ya);
        if((dl3<min&&dl3!=-1)||min==-1)min=dl3;
        dl4=ras(xc,yc,xd,yd,xb,yb);
        if((dl4<min&&dl4!=-1)||min==-1)min=dl4;
        if(min==-1){
            //В случае, если невозможно опустить высоту найдём минимальное расстояние между точками.
            dl1=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
            min=dl1;
            dl2=sqrt((xb-xd)*(xb-xd)+(yb-yd)*(yb-yd));
            if(dl2<min)min=dl2;
            dl3=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
            if(dl3<min)min=dl3;
            dl4=sqrt((xa-xd)*(xa-xd)+(ya-yd)*(ya-yd));
            if(dl4<min)min=dl4;
        }
    }
    cout<< fixed <<setprecision(20) << min;


    return 0;
}