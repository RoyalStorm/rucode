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

double angle(const Point& a, const Point& b) {
    return acos(dP(a, b) / (len(a) * len(b)));
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    Point a, b;
    cin >> a >> b;

    cout << setprecision(13) << fixed << angle(a, b);

    return 0;
}