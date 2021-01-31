#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const ll maxA = 1e9 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll a[maxN];

vector<ar<int, 2>> q[maxN];

int reach[maxN];

ll st[maxN*4];
ll lazy[maxN*4];

ll res[maxN];

void apply_st(int i, int l, int r, ll val) {
    st[i] += val*(r - l + 1);
    lazy[i] += val;
}

void down_st(int i, int l, int r) {
    int m = (l + r)/2;
    apply_st(2*i, l, m, lazy[i]);
    apply_st(2*i + 1, m + 1, r, lazy[i]);
    lazy[i] = 0;
}

void update_st(int u, int v, ll val, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return;

    if (u <= l && r <= v) {
        apply_st(i, l, r, val);
        return;
    }

    int m = (l + r)/2;
    down_st(i, l, r);
    update_st(u, v, val, 2*i, l, m);
    update_st(u, v, val, 2*i + 1, m + 1, r);

    st[i] = st[2*i] + st[2*i + 1];
}

ll get_st(int u, int v, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return 0;

    if (u <= l && r <= v) 
        return st[i];

    int m = (l + r)/2;
    down_st(i, l, r);
    ll res = get_st(u, v, 2*i, l, m) + get_st(u, v, 2*i + 1, m + 1, r);
    st[i] = st[2*i] + st[2*i + 1];
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nq;
    cin >> n >> nq;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = maxA;

    for (int i = 0; i < nq; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        q[x].push_back({y, i});
    }

    vector<int> k;
    k.push_back(n);
    for (int i = n - 1; i >= 0; --i) {
        while (a[i] >= a[k.back()]) {
            update_st(k.back(), reach[k.back()], a[i] - a[k.back()]);
            k.pop_back();
        }
        reach[i] = k.back() - 1;
        k.push_back(i);

        for (auto u: q[i]) 
            res[u[1]] = get_st(i, u[0]);
    }

    for (int i = 0; i < nq; ++i)
        cout << res[i] << '\n';
}
