#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

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

    bool operator<(Point other) {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    Point operator-(Point other) {
        return Point{x - other.x, y - other.y};
    }
};

int n;
vector<Point> a;

vector<Point> st;

vector<Point> hull;


template<typename T>
int sign(T x) {
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

bool on_line(Point a, Point b, Point c) {
    auto ab = b - a;
    auto ac = c - a;
    if (ab.x == 0 || ac.x == 0)
        return ab.x + ac.x == 0;

    return ab.y*ac.x == ac.y*ab.x;
}

int get_orientation(Point a, Point b, Point c) {
    if (on_line(a, b, c))
        return 0;

    auto ab = b - a;
    auto cb = b - c;
    ll dot = ab.x*cb.x + ab.y*cb.y;
    ll det = ab.x*cb.y - ab.y*cb.x;


    // cerr << a.x << " " << a.y << "\n";
    // cerr << b.x << " " << b.y << "\n";
    // cerr << c.x << " " << c.y << "\n";
    // cerr << (atan2(det, dot)) << "\n";
    // cerr << "-----------\n";
    return sign(atan2(det, dot));
}

void make_convex_hull_orientation(int ori) {
    st.clear();
    for (int i = 0; i < n; ++i) {
        while (st.size() > 1) {
            int m = st.size();
            if (get_orientation(st[m - 2], st[m - 1], a[i])*ori < 0)
                st.pop_back();
            else
                break;
        }

        st.push_back(a[i]);
    }
}

void make_convex_hull() {
    sort(a.begin(), a.end());
    make_convex_hull_orientation(1);
    hull = st;
    make_convex_hull_orientation(-1);
    for (int i = st.size() - 2; i > 0; --i)
        hull.push_back(st[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;

    make_convex_hull();

    cout << hull.size() << "\n";
    for (auto p: hull)
        cout << p.x << " " << p.y << "\n"; 
}
