#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;
const int maxN = 11;
const int maxM = 1000 + 10;
const int MOD = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;
vector<int> adj[1 << maxN];

bool con[1 << maxN][1 << maxN];

int f[maxM][1 << maxN];

void make_con() {
    for (int u = 0; u < (1 << n); ++u)
    for (int v = 0; v < (1 << n); ++v) {
        con[u][v] = (u | v) == ((1 << n) - 1);
        if (!con[u][v])
            continue;

        int x = u & v;
        for (int i = 0; i < n; ++i)
            if (gb(x, i)) {
                if (i == n - 1 || !gb(x, i + 1))
                    con[u][v] = 0;

                i++;
            }

    }

    for (int u = 0; u < (1 << n); ++u)
    for (int v = 0; v < (1 << n); ++v) 
        if (con[u][v])
            adj[u].push_back(v);
}

void dp() {
    f[0][(1 << n) - 1] = 1;
    for (int i = 0; i < m; ++i)
        for (int u = 0; u < (1 << n); ++u) 
            if (f[i][u])
                for (int v: adj[u])
                    f[i + 1][v] = (f[i + 1][v] + f[i][u]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    make_con();
    dp();
    cout << f[m][(1 << n) - 1] << '\n';

    // for (int i = 1; i <= m; ++i) {
    //     for (int u = 0; u < (1 << n); ++u)
    //         cout << f[i][u] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    // for (int u = 0; u < (1 << n); ++u) {
    //     for (int v = 0; v < (1 << n); ++v)
    //         cout << con[u][v] << ' ';
    //     cout << '\n';
    // }
}
