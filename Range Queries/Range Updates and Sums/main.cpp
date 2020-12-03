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
    long long ua, us;  
    bool pushed;
};

int n, m;
int a[maxN];

Node st[maxN*4];

void make_ST(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        st[i] = {a[l], 0, 0, 1};
        return;
    }

    int m = (l + r)/2;
    make_ST(2*i, l, m);
    make_ST(2*i + 1, m + 1, r);

    st[i].s = st[2*i].s + st[2*i + 1].s;
    st[i].pushed = 1;
}

void push(int i, int l, int r) {
    int m = (l + r)/2;
    if (!st[i].pushed) {
        st[i*2].s = (st[i].ua + st[i].us)*(m - l + 1);
        st[i*2 + 1].s = (st[i].ua + st[i].us)*(r - m);
        st[i*2].ua = st[i*2 + 1].ua = st[i].ua;
        st[i*2].us = st[i*2 + 1].us = st[i].us;
        st[i*2].pushed = st[i*2 + 1].pushed = 0;
    }
    else {
        st[2*i].s += (m - l + 1)*st[i].ua;
        st[2*i + 1].s += (r - m)*st[i].ua;

        st[2*i].ua += st[i].ua;
        st[2*i + 1].ua += st[i].ua;
    }

    st[i].us = 0;
    st[i].ua = 0;
    st[i].pushed = 1;
}

void update_ST(int u, int v, long long ua, long long us, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) {
        if (ua) {
            st[i].s += (r - l + 1)*ua;
            st[i].ua += ua;
        }
        else  {
            st[i].s = (r - l + 1)*us;
            st[i].us = us;
            st[i].ua = 0;
            st[i].pushed = 0;
        }
        return;
    }

    if (r < u || v < l)
        return;

    push(i, l, r);
    int m = (l + r)/2;
    update_ST(u, v, ua, us, 2*i, l, m);
    update_ST(u, v, ua, us, 2*i + 1, m + 1, r);
    st[i].s = st[2*i].s + st[2*i + 1].s;
}

long long get_ST(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) 
        return st[i].s;

    if (r < u || v < l)
        return 0;

    push(i, l, r);
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

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    make_ST();

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 1) {
            int x;
            cin >> x;
            update_ST(a, b, x, 0);
        }
        else if (c == 2) {
            int x;
            cin >> x;
            update_ST(a, b, 0, x);
        } else 
            cout << get_ST(a, b) << '\n';
    }
}
