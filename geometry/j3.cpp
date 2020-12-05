#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;

    Point() {}

    Point(double x_, double y_) : x(x_), y(y_) {}
};

Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator*(const Point &a, const double &k) {
    return Point(a.x * k, a.y * k);
}

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

double dP(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double cP(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double len(const Point &a) {
    return hypot(a.x, a.y);
}

istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator<<(ostream &out, const Point &p) {
    out << setprecision(8) << fixed << p.x << " " << p.y;
    return out;
}

int main() {
    Point a1, b1, a2, b2, p;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    if (cP(b1 - a1, b2 - a2) == 0) {
        if (((a2.y - a1.y) * (b1.x - a1.x)) == ((a2.x - a1.x) * (b1.y - a1.y)))
            cout << 2;
        else
            cout << 0;
    } else {
        double t = -(cP(a1 - a2, b2 - a2) / cP(b1 - a1, b2 - a2));
        p = a1 + (b1 - a1) * t;
        cout << 1 << " " << p;
    }

    return 0;
}