#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
vector<int> adj[maxN];

int d[maxN];

int fc[maxN][2];
int dp[maxN];

int res[maxN];

void DFS_fc(int u = 1, int p = 0) {
    d[u] = 1;

    for (int v: adj[u]) {
        if (p == v)
            continue;

        DFS_fc(v, u);
        d[u] = max(d[u], d[v] + 1);

        if (d[fc[u][1]] < d[v]) 
            fc[u][1] = v;
        if (d[fc[u][0]] < d[fc[u][1]])
            swap(fc[u][0], fc[u][1]);
    }
}

void DFS_dp(int u = 1, int p = 0) {
    int apc = (fc[p][0] == u ? fc[p][1] : fc[p][0]);
    dp[u] = max(d[apc], dp[p]) + 1;
    res[u] = max(d[fc[u][0]], dp[u]);

    for (int v: adj[u]) {
        if (p == v)
            continue;

        DFS_dp(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    d[0] = -1;
    dp[0] = -1;
    DFS_fc();
    DFS_dp();

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}