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

int n, m;
int a[maxN];
array<int, 3> q[maxM];

int inext[maxN];
map<int, int> iprev;

int fen[maxN];

int res[maxM];

void add_fenwick(int i, int val) {
    for (; i <= n; i += i & -i)
        fen[i] += val;
}

int get_fenwick(int i) {
    int res = 0;
    for (; i ; i &= i - 1)
        res += fen[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (iprev.find(a[i]) == iprev.end()) 
            add_fenwick(i, 1);
        else 
            inext[iprev[a[i]]] = i;
        
        iprev[a[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }
    sort(q, q + m);

    for (int i = 0; i < m; ++i) {
        for (int j = (i? q[i - 1][0]: 1); j < q[i][0]; ++j) {
            add_fenwick(j, -1);
            if (inext[j])
                add_fenwick(inext[j], 1);
        }

        res[q[i][2]] = get_fenwick(q[i][1]) - get_fenwick(q[i][0] - 1);
    }

    for (int i = 0; i < m; ++i)
        cout << res[i] << '\n';
}
