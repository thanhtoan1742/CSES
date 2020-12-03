#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const int maxLN = 25;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, m;
vector<int> adj[maxN];

int asc[maxN][maxLN];

void DFS(int u = 1, int p = 0) {
    asc[u][0] = p;  
    for (int i = 1; i < maxLN; ++i)
        asc[u][i] = asc[asc[u][i - 1]][i - 1];

    for (int v: adj[u]) {
        if (v == p)
            continue;

        DFS(v, u);
    }
}

int get_asc(int u, int k) {
    for (int i = maxLN - 1; i >= 0; --i) 
        if (k >= (1 << i)) {
            u = asc[u][i];
            k -= (1 << i);
        }

    return (u ? u : -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    DFS();

    while (m--) {
        int x, k;
        cin >> x >> k;
        cout << get_asc(x, k) << '\n';
    }
}
