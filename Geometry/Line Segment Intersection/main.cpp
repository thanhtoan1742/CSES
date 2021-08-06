#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
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

struct Point {
    ll x, y;
};

ll sign(ll a) {
    if (a > 0)
        return 1;
    if (a < 0)
        return -1;
    return 0;
}

ll double_area(const vector<Point>& a) {
    int n = a.size();
    ll area = (a[n - 1].x - a[0].x) * (a[n - 1].y + a[0].y);
    for (int i = 0; i < n - 1; ++i)
        area += (a[i].x - a[i + 1].x)*(a[i].y + a[i + 1].y);

    // for (auto u: a)
    //     cout << u.x <<  " " << u.y << "\n";
    // cout << "area: " << area << "\n";
    return area;
}

bool intersect(vector<Point>& a) {
    ll i1 = sign(double_area({a[0], a[1], a[2]}));
    ll i2 = sign(double_area({a[0], a[1], a[3]}));
    if (i1 * i2 > 0)
        return 0;

    if (a[0].x > a[1].x)
        swap(a[0], a[1]);
    if (a[2].x > a[3].x)
        swap(a[2], a[3]);
    if (i1 == 0 && i2 == 0 && (a[1].x < a[2].x || a[3].x < a[0].x))
        return 0;

    for (int i = 0; i < 4; ++i)
        swap(a[i].x, a[i].y);
    if (a[0].x > a[1].x)
        swap(a[0], a[1]);
    if (a[2].x > a[3].x)
        swap(a[2], a[3]);
    if (i1 == 0 && i2 == 0 && (a[1].x < a[2].x || a[3].x < a[0].x))
        return 0;
    for (int i = 0; i < 4; ++i)
        swap(a[i].x, a[i].y);

    i1 = sign(double_area({a[2], a[3], a[0]}));
    i2 = sign(double_area({a[2], a[3], a[1]}));
    if (i1 * i2 > 0)
        return 0;

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        vector<Point> a(4);
        for (int i = 0; i < 4; ++i)
            cin >> a[i].x >> a[i].y;

        if (intersect(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
