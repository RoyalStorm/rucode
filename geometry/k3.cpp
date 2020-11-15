#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const double eps = 1e-9;

struct Point {
    long double x, y;

    Point() {}

    Point(long double x_, long double y_) : x(x_), y(y_) {}
};

Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator*(const Point &a, const long double &k) {
    return Point(a.x * k, a.y * k);
}

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator<<(ostream &out, const Point &p) {
    out << setprecision(5) << fixed << p.x << " " << p.y;
    return out;
}

Point getPoint(long double A, long double B, long double C, long double start) {
    // Ax + By + C = 0
    if (fabs(B) < eps) {
        long double x = -C / A;
        return Point(x, start);
    } else {
        long double y = -(C + (A * start)) / B;
        return Point(start, y);
    }
}

int main() {
    long double R, A, B, C;
    Point p;
    cin >> p >> R >> A >> B >> C;

    Point p1 = getPoint(A, B, C, 1.0);
    Point p2 = getPoint(A, B, C, 4.0);

    p1 = p1 - p;
    p2 = p2 - p;

    long double Fx = p2.x - p1.x;
    long double Fy = p2.y - p1.y;

    long double a = pow(Fx, 2.0) + pow(Fy, 2.0);
    long double b = 2.0 * (p1.x * Fx + p1.y * Fy);
    long double c = pow(p1.x, 2.0) + pow(p1.y, 2.0) - pow(R, 2.0);

    long double D = (pow(b, 2.0) - 4.0 * a * c);

    if ((fabs(a) < eps && fabs(b) < eps) || D < 0.0)
        cout << 0 << endl;
    else if (fabs(a) < eps) {
        cout << 1 << endl;
        long double k1 = -c / b;
        cout << p1 + p + ((p2 - p1) * k1);
    } else if (fabs(D) < eps) {
        cout << 1 << endl;
        long double k1 = -b / (2.0 * a);
        cout << p1 + p + ((p2 - p1) * k1);
    } else {
        long double k1 = (-b + sqrt(D)) / (2.0 * a);
        long double k2 = (-b - sqrt(D)) / (2.0 * a);

        Point res1 = p1 + p + ((p2 - p1) * k1);
        Point res2 = p1 + p + ((p2 - p1) * k2);

        vector<pair<long double, long double>> v;
        v.push_back(make_pair(res1.x, res1.y));
        v.push_back(make_pair(res2.x, res2.y));

        sort(v.begin(), v.end());

        cout << v.size() << endl;
        for (auto &pair : v)
            cout << setprecision(5) << fixed << pair.first << " " << pair.second << endl;
    }

    return 0;
}
