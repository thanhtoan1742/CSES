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

struct Node {
    long long s;
    long long urec, uslp;
};

int n;
long long a[maxN];

Node st[maxN*4];

void make_ST(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        st[i] = {a[l], 0, 0};
        return;
    }

    int m = (l + r)/2;
    make_ST(2*i, l, m);
    make_ST(2*i + 1, m + 1, r);

    st[i].s = st[2*i].s + st[2*i + 1].s;
}

void down_ST(int i, int l, int r, long long uslp, long long urec) {
    st[i].s += uslp*(r - l + 1)*(r - l + 2)/2 + urec*(r - l + 1);
    st[i].urec += urec;
    st[i].uslp += uslp;
}

void push_ST(int i, int l, int r) {
    int m = (l + r)/2;
    down_ST(2*i, l, m, st[i].uslp, st[i].urec);
    down_ST(2*i + 1, m + 1, r, st[i].uslp, st[i].urec + st[i].uslp*(m - l + 1));

    st[i].urec = 0;
    st[i].uslp = 0;
}

void update_ST(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) {
        down_ST(i, l, r, 1, l - u);
        return;
    }

    if (v < l || r < u)
        return;

    push_ST(i, l, r);

    int m = (l + r)/2;
    update_ST(u, v, 2*i, l, m);
    update_ST(u, v, 2*i + 1, m + 1, r);

    st[i].s = st[2*i].s + st[2*i + 1].s;
}

long long get_ST(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v)   
        return st[i].s;

    if (v < l || r < u)
        return 0;

    push_ST(i, l, r);

    int m = (l + r)/2;
    long long res = get_ST(u, v, 2*i, l, m) 
        + get_ST(u, v, 2*i + 1, m + 1, r);

    st[i].s = st[2*i].s + st[2*i + 1].s;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    make_ST();
    while (q--) {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 1) {
            update_ST(x, y);
        }
        else {
            cout << get_ST(x, y) << '\n';
        }
    }
}
