#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    long long x, y;
    Point() {}
    Point(long long x_, long long y_):
        x(x_),
        y(y_) {
    }
};

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

Point operator +(const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator *(const Point& a, const int& k) {
    return Point(a.x * k, a.y * k);
}

long long cP(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

inline bool is_intersect(int a, int b, int c, int d) {
    if (a > b)
        swap(a, b);

    if (c > d)
        swap(c, d);

    return min(b, d) >= max(a, c);
}

int main() {
    Point a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    string res;
    if (cP(c - a, b - a) == 0 && cP(d - a, b - a) == 0) {
        if (is_intersect(a.x, b.x, c.x, d.x) && is_intersect(a.y, b.y, c.y, d.y))
            res = "YES";
        else
            res = "NO";
    } else {
        long long s_1 = cP(b - a, d - a) * cP(b - a, c - a);
        long long s_2 = cP(d - c, b - c) * cP(d - c, a - c);

        if (s_1 <= 0 && s_2 <= 0)
            res = "YES";
        else
            res = "NO";
    }

    cout << res;

    return 0;
}