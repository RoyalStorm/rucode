#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x_, int y_) :x(x_), y(y_) {}
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

int dP(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

int cP(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

double len(const Point& a) {
    return hypot(a.x, a.y);
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    Point a, b, p;
    cin >> p >> a >> b;

    long double res;
    if (dP(b - a, p - a) >= 0 && dP(a - b, p - b) >= 0)
        res = abs(cP(a - p, b - p) / len(a - b));
    else
        res = min(len(p - a), len(p - b));

    cout << setprecision(13) << fixed << res;

    return 0;
}