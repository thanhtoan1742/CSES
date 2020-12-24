#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<double> a(k), b(k);
    fill(a.begin(), a.end(), 1.0/k);
    fill(b.begin(), b.end(), 0);
    for (int i = 1; i < n; ++i) {
        fill(b.begin(), b.end(), 0);

        for (int x = 1; x <= k; ++x)
        for (int y = 1; y <= k; ++y)
            b[max(x, y) - 1] += a[x - 1]/k;

        swap(a, b);
    }


    double res = 0;
    for (int i = 1; i <= k; ++i)
        res += a[i - 1]*i;
    cout << fixed << setprecision(6) << res << '\n';
}
