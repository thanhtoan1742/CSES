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
const int maxN = 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k1, k2;
vector<int> adj[maxN];

ll f[maxN][maxN];
ll res[maxN];

void DFS(int u = 1, int p = 0) {
    f[u][0] = 1;
    for (int v: adj[u]) {
        if (v == p)
            continue;

        DFS(v, u);

        for (int i = 0; i <= n; ++i)
            for (int j = 0; i + j <= n; ++j)
                res[i + j] += f[u][i]*f[v][j];

        for (int i = 0; i < n; ++i)
            f[u][i + 1] += f[v][i];
    }

    for (int i = 0; i < n; ++i)
        res[i] += f[u][i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k1 >> k2;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS();

    for (int i = 0; i < n; ++i)
        cout << i << ": " << res[i] << '\n';
}
