#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
int k = 1;

int fen[maxN];

int get_fen(int i) {
    int res = 0;
    for (; i; i -= i & -i)
        res += fen[i];
    return res;
}

void add_fen(int i, int u) {
    for (; i <= n; i += i & -i)
        fen[i] += u;
}

int skip(int s, int sz) {
    int st = k%sz + 1;
    int l = s, r = n;
    int t = get_fen(n) - get_fen(s - 1);
    if (t < st) {
        st -= t;
        l = 1;
        r = s - 1;
        s = 1;
    }

    while (l < r) {
        int m = (l + r)/2;
        if (get_fen(m) - get_fen(s - 1) < st)
            l = m + 1;
        else 
            r = m;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        add_fen(i, 1);

    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        idx = skip(idx, n - i + 1);
        add_fen(idx, -1);
        cout << idx << " ";
    }
    cout << "\n";
}
