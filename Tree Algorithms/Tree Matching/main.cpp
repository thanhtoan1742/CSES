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

int matched[maxN];

int match(int u = 1, int p = 0) {
    if (adj[u].size() == 1 && p == adj[u][0]) 
        return 0;

    int res = 0;
    for (int v: adj[u]) {
        if (v == p)
            continue;

        res += match(v, u);
        if (!matched[v] && !matched[u]) {
            matched[u] = 1;
            matched[v] = 1;
            ++res;
        }
    }
    return res;
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

    cout << match(1) << '\n';
}
