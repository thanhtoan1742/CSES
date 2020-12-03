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

long long sd[maxN];
int sc[maxN];

long long res[maxN];

void DFS_sd(int u = 1, int p = 0) {
    sc[u] = 1;
    sd[u] = 0;

    for (int v: adj[u]) {
        if (v == p) 
            continue;

        DFS_sd(v, u);
        sc[u] += sc[v];
        sd[u] += sd[v] + sc[v];
    }
}

void DFS_res(int u = 1, int p = 0, long long su = 0) {
    res[u] = su + sd[u];

    for (int v: adj[u]) {
        if (v == p) 
            continue;

        DFS_res(v, u, res[u] - sd[v] - sc[v] + n - sc[v]);
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

    DFS_sd();
    DFS_res();

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}
