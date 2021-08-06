#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
 
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> a(n);
    while (n--) {
        cin >> a[n][0] >> a[n][1];
    }
    a.push_back(a[0]);

    ll area = 0;
    for (int i = 0; i + 1 < a.size(); ++i) {
        area += (a[i][0] - a[i + 1][0])*(a[i][1] + a[i + 1][1]);
    }
    area = abs(area);
    cout << area << "\n";
 
}