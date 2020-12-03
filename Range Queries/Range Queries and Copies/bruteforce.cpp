#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const int maxM = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

struct Query {
    int type;
    int u, v, i;
};

int n, m;
vector<vector<int>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    a.push_back(vector<int>());
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[0].push_back(x);
    }

    while (m--) {
        int o, k;
        cin >> o >> k; --k;

        if (o == 1) {
            int u, v;
            cin >> u >> v; --u;
            a[k][u] = v;
        }
        if (o == 2) {
            int u, v;
            cin >> u >> v; --u; --v;

            long long s = 0;
            for (int i = u; i <= v; ++i)
                s += a[k][i];
            if (s == 248) {
            }
            cout << s << '\n';
        }
        if (o == 3) {
            a.push_back(a[k]);
        }
    }

}
