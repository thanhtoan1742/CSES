#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 1000 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, m;
int a[maxN][maxN];

int fen[maxN][maxN];

void add_fenwick(int i, int j, int val) {
    for (; i <= n; i += i & -i) 
        for (int l = j; l <= n; l += l & -l)
            fen[i][l] += val;
}

int get_fenwick(int i, int j) {
    int res = 0;
    for (; i; i &= i - 1)
        for (int l = j; l; l &= l - 1)
            res += fen[i][l];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            a[i][j] = s[j - 1] == '*';

            if (a[i][j])
                add_fenwick(i, j, 1);
        }

    }

    while (m--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, y;
            cin >> x >> y;

            add_fenwick(x, y, a[x][y]? -1: 1);
            a[x][y] = !a[x][y];
        }
        else {
            int x, y, u, v;
            cin >> x >> y >> u >> v;

            cout << get_fenwick(u, v)
                - get_fenwick(u, y - 1)
                - get_fenwick(x - 1, v)
                + get_fenwick(x - 1, y - 1) << '\n';
        }
    }
}
