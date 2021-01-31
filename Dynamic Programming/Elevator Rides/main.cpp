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
const int maxN = 21;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
int x;
int a[maxN];

int tr[1 << maxN];
ar<int, 2> f[1 << maxN];

void dp() {
    f[0] = {0, x};
    for (int u = 1; u < (1 << n); ++u) {
        f[u] = {n + 1, 0};
        for (int i = 0; i < n; ++i)
            if (gb(u, i)) {
                auto option = f[u - (1 << i)];
                option[1] += a[i];
                if (option[1] > x) {
                    option[1] = a[i];
                    option[0]++;
                }

                if (f[u] > option) {
                    f[u] = option;
                    tr[u] = u - (1 << i);
                }
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp();

    cout << f[(1 << n) - 1][0] << '\n';
}