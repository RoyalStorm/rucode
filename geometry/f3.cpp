#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double x_, double y_):
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

Point operator *(const Point& a, const double& k) {
    return Point(a.x * k, a.y * k);
}

double len(const Point& a) {
    return hypot(a.x, a.y);
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator <<(ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
}

int main() {
    Point A, B, C;
    cin >> A >> B >> C;

    double l1 = len(C - B);
    double l2 = len(A - C);
    double l3 = len(B - A);

    Point x((l1 * A.x + l2 * B.x + l3 * C.x) / (l1 + l2 +l3), (l1 * A.y + l2 * B.y + l3 * C.y) / (l1 + l2 + l3));
    cout << setprecision(13) << fixed << x;

    return 0;
}