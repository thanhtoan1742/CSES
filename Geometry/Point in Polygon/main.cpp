#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;

const double pi = M_PI;
const double eps = 0.000001;

template<class T> 
using indexed_set = tree<
    T, 
    null_type, 
    less<T>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
>;
using ll = long long;

struct Point {
    ll x, y;

    Point(ll _x, ll _y)
    : x(_x), y(_y) {
    }

    Point operator-(Point other) {
        return Point(x - other.x, y - other.y);
    }

    double norm() {
        return sqrt(x*x + y*y);
    }
};

int n, m;
vector<Point> a;

bool on_segment(Point a, Point b, Point c) {
    return abs((a - b).norm() - (a - c).norm() - (b - c).norm()) < eps;
}

double angle(Point a, Point b, Point c) {
    auto ab = b - a;
    auto cb = b - c;
    auto dot = ab.x*cb.x + ab.y*cb.y;
    auto det = ab.x*cb.y - ab.y*cb.x;
    return atan2(det, dot);
}

int check(Point p) {
    for (int i = 0; i < n; ++i)
        if (on_segment(a[i], a[i + 1], p))
            return 0;

    double ang = 0;
    for (int i = 0; i < n; ++i)
        ang += angle(a[i], p, a[i + 1]);
    ang = abs(ang);

    if (ang < pi)
        return -1;
    else
        return 1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    a.push_back(a[0]);

    while (m--) {
        int x, y;
        cin >> x >> y;
        auto res = check({x, y});
        if (res == 0)
            cout << "BOUNDARY\n";
        else if (res == 1)
            cout << "INSIDE\n";
        else 
            cout << "OUTSIDE\n";
    }
}