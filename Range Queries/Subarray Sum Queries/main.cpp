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

struct ST_Node{
    long long sm, lm, rm, s;
};

ST_Node combine(const ST_Node& a, const ST_Node& b) {
    return {
        max(max(a.sm, b.sm), a.rm + b.lm),
        max(a.lm, a.s + b.lm),
        max(b.rm, a.rm + b.s),
        a.s + b.s
    };
}

int n, m;
int a[maxN];

ST_Node st[maxN*4];
int pos[maxN];

void make_ST(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        st[i] = {a[l], a[l], a[l], a[l]};
        pos[l] = i;
        return;
    }

    int m = (l + r)/2;
    make_ST(i*2, l, m);
    make_ST(i*2 + 1, m + 1, r);
    st[i] = combine(st[2*i], st[2*i + 1]);
}

void update_ST(int k, int x) {
    a[k] = x;
    st[pos[k]] = {x, x, x, x};

    int i = pos[k]/2;
    while (i) {
        st[i] = combine(st[2*i], st[2*i + 1]);
        i /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    make_ST();

    for (int i = 1; i <= m; ++i) {
        int k, x;
        cin >> k >> x;
        update_ST(k, x);
        cout << max(0ll, st[1].sm) << '\n';
    }
}