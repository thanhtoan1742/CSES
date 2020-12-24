#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 100 + 10;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

array<array<double, maxN>, maxN> p, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    double res = 0;
    for (int u = 0; u < maxN; ++u) {
        for (int j = 0; j <= n; ++j)
            p[u][j] = 0;
        p[u][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int u = 1; u <= a[i]; ++u)
            for (int v = u + 1; v < maxN; ++v)
                for (int j = 1; j <= n; ++j)
                {
                    res += p[v][j]*j/a[i];
                    // cerr << u << ' ' << v << ' ' << j << ' ' << p[v][j] << '\n';
                }

        // cerr << "res " << res << '\n';

        for (int u = 1; u <= a[i]; ++u) {
            q[u][0] = p[u][0]*(a[i] - 1)/a[i];
            for (int j = 1; j <= n; ++j)
                q[u][j] = p[u][j]*(a[i] - 1)/a[i] + p[u][j - 1]/a[i];
        }
        for (int u = a[i] + 1; u < maxN; ++u)
            for (int j = 0; j <= n; ++j)
                q[u][j] = p[u][j];
        swap(p, q);
    }

    cout << fixed << setprecision(6) << res << '\n';
}
