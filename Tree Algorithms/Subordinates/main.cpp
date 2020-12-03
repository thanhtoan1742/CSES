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
int p[maxN];
int deg[maxN];

int res[maxN];

void go_up(int u) {
    if (u == 1)
        return;

    deg[u]--;

    deg[p[u]]--;
    res[p[u]] += res[u] + 1;
    if (!deg[p[u]])
        go_up(p[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        deg[p[i]]++;
    }

    for (int i = 1; i <= n; ++i)
        if (!deg[i])
            go_up(i);

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}
