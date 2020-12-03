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

int f[maxN];

int DFS(int u, int p = 0) {
    f[u] = 1;

    int f1 = 0, f2 = 0;
    int res = 0;
    for (int v: adj[u])
        if (v != p) {
            maximize(res, DFS(v, u));
            maximize(f[u], f[v] + 1);

            if (f[v] > f2)
                f2 = f[v];
            if (f2 > f1)
                swap(f1, f2);
        }   

    return max(res, f1 + f2 + 1);
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

    cout << DFS(1) - 1 << '\n';
}
