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
ar<int, 3> a[maxN];

int b[maxN];

int rc[maxN], rbc[maxN];

int fen[maxN];

void add_fenwick(int u, int v) {
    for (u++; u <= n; u += u & -u) 
        fen[u] += v;
}

int get_fenwick(int u) {
    int s = 0;
    for (u++; u; u -= u & -u) 
        s += fen[u];
    return s;
}

void reset_fenwick() {
    for (int i = 1; i <= n; ++i)
        fen[i] = 0;
}

bool cmp_rc(ar<int, 3> a, ar<int, 3> b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a, a + n, cmp_rc);

    for (int i = 0; i < n; ++i)
        b[i] = a[i][1];
    sort(b, b  + n);
    for (int i = 0; i < n; ++i)
        a[i][1] = lower_bound(b, b + n, a[i][1]) - b;

    for (int i = n - 1; i >= 0; --i) {
        rc[a[i][2]] = get_fenwick(a[i][1]);
        add_fenwick(a[i][1], 1);
    }
 

    reset_fenwick();
    for (int i = 0; i < n; ++i) {
        rbc[a[i][2]] = i - get_fenwick(a[i][1] - 1);
        add_fenwick(a[i][1], 1);
    }
 
 
    for (int i = 0; i < n; ++i)
         cout << rc[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
         cout << rbc[i] << ' ';
    cout << '\n';
}