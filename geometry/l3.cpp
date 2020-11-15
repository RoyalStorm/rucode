#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cfloat>

using namespace std;

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
    return fabs(a.x - b.x) < LDBL_EPSILON && fabs(a.y - b.y) < LDBL_EPSILON;
}

istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator<<(ostream &out, const Point &p) {
    out << setprecision(20) << fixed << p.x << " " << p.y;
    return out;
}

Point getPoint(long double A, long double B, long double C, long double start) {
    // Ax + By + C = 0
    if (fabs(B) < LDBL_EPSILON) {
        long double x = -C / A;
        return Point(x, start);
    } else {
        long double y = -(C + (A * start)) / B;
        return Point(start, y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    vector<pair<int, pair<Point, Point>>> res(m);

    for (int i = 0; i < m; i++) {
        Point c1, c2;
        long double r1, r2;

        cin >> c1 >> r1;
        cin >> c2 >> r2;

        if (c1 == c2) {
            if (fabs(r1 - r2) < LDBL_EPSILON)
                res[i] = {-1, {}};
            else
                res[i] = {0, {}};
        } else {
            c2 = c2 - c1;

            long double A = -2.0 * c2.x;
            long double B = -2.0 * c2.y;
            long double C = pow(c2.x, 2.0) + pow(c2.y, 2.0) + pow(r1, 2.0) - pow(r2, 2.0);

            Point p1 = getPoint(A, B, C, 1.0);
            Point p2 = getPoint(A, B, C, 4.0);

            long double Fx = p2.x - p1.x;
            long double Fy = p2.y - p1.y;

            long double a = pow(Fx, 2.0) + pow(Fy, 2.0);
            long double b = 2.0 * (p1.x * Fx + p1.y * Fy);
            long double c = pow(p1.x, 2.0) + pow(p1.y, 2.0) - pow(r1, 2.0);

            long double D = pow(b, 2.0) - 4.0 * a * c;

            if (D < 0.0)
                res[i] = {0, {}};
            else if (fabs(a) < LDBL_EPSILON) {
                long double k1 = -c / b;
                Point ip1 = p1 + c1 + ((p2 - p1) * k1); // Intersection point

                res[i] = {1, {ip1, ip1}};
            } else if (fabs(D) < LDBL_EPSILON) {
                long double k1 = -b / (2.0 * a);
                Point ip1 = p1 + c1 + ((p2 - p1) * k1); // Intersection point

                res[i] = {1, {ip1, ip1}};
            } else {
                long double k1 = (-b + sqrt(D)) / (2.0 * a);
                long double k2 = (-b - sqrt(D)) / (2.0 * a);

                Point ip1 = p1 + c1 + ((p2 - p1) * k1);
                Point ip2 = p1 + c1 + ((p2 - p1) * k2);

                vector<pair<long double, long double>> v;
                v.push_back(make_pair(ip1.x, ip1.y));
                v.push_back(make_pair(ip2.x, ip2.y));

                sort(v.begin(), v.end());

                res[i] = {2, {Point(v[0].first, v[0].second), Point(v[1].first, v[1].second)}};
            }
        }
    }

    for (int i = 0; i < m; i++) {
        pair<int, pair<Point, Point>> pair_ = res[i];

        cout << pair_.first << endl;

        if (pair_.first == 1)
            cout << pair_.second.first << endl;
        else if (pair_.first == 2) {
            cout << pair_.second.first << endl;
            cout << pair_.second.second << endl;
        }

        cout << endl;
    }

    return 0;
}

/*
2
3 5 8
3 5 8
0 0 2
4 0 2

2
0 0 2
4 0 2
0 0 2
4 0 2

2
7 2 1
7 3 1
7 2 1
7 3 1
*/
