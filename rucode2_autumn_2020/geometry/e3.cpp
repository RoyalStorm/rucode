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

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    Point a, b, c;
    cin >> a >> b >> c;

    cout << setprecision(13) << fixed << (a.x + b.x + c.x) / 3.0 << " " << (a.y + b.y + c.y) / 3.0;

    return 0;
}