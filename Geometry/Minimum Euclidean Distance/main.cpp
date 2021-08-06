#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
 
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

using Point = array<ll, 2>;

int n;
vector<Point> a;

ll dis_sqr(Point a, Point b) {
    return sqr(a[0] - b[0]) + sqr(a[1] - b[1]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];

    ll mean_x = 0;
    ll mean_y = 0;
    for (int i = 0; i < n; ++i) {
        mean_x += a[i][0];
        mean_y += a[i][1];
    }
    mean_x /= n;
    mean_y /= n;

    Point magic{mean_x, mean_y};
    sort(a.begin(), a.end(), 
        [magic](Point a, Point b) {return dis_sqr(a, magic) < dis_sqr(b, magic); }
    );

    int m = 500;
    ll res = (1ll << 62) - 1 + (1ll << 62);
    for (int i = 0; i < n; ++i)
        for (int j = max(0, i - m); j < min(n, i + m); ++j) {
            if (i == j)
                continue;

            res = min(res, dis_sqr(a[i], a[j]));
        }

    cout << res << "\n";
}