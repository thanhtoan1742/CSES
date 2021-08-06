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

ll solve(vector<Point> a) {
    ll area = 0;
    for (int i = 0; i < 3; ++i)
        area += (a[i].x - a[i + 1].x)*(a[i].y + a[i + 1].y);
    return area;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        vector<Point> a(3);
        for (int i = 0; i < 3; ++i)
            cin >> a[i].x >> a[i].y;
        a.push_back(a[0]);

        ll res = solve(a);

        if (res == 0)
            cout << "TOUCH\n";
        else if (res < 0)
            cout << "RIGHT\n";
        else
            cout << "LEFT\n";
    }
 
}