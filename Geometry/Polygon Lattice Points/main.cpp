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
};

int n;
vector<Point> a;

ll double_area() {
    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += (a[i].x - a[i + 1].x)*(a[i].y + a[i + 1].y);
    return abs(res);
}

ll count_on_edge(Point a) {
    a.x = abs(a.x);
    a.y = abs(a.y);

    if (a.x == 0 || a.y == 0)
        return a.x + a.y;
    return gcd(a.x, a.y);
}

ll count_on_edges() {
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += count_on_edge(a[i] - a[i + 1]);
    }
    return res;
}

ll count_inside() {
    // Pick's theorem
    return (double_area() - count_on_edges() + 2)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    a.push_back(a[0]);

    cout << count_inside() << " " << count_on_edges() << "\n";
}