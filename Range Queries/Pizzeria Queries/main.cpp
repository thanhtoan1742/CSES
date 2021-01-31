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
const ll maxVal = 1e18 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct ST_Node {
    ll mps, mns;
    ll lazy_p, lazy_n;

    ST_Node(ll _mps = 0, ll _mns = 0, ll _lazy_p = 0, ll _lazy_n = 0)
    : mps(_mps), mns(_mns), lazy_p(_lazy_p), lazy_n(_lazy_n) {
    }
};

ST_Node combine_st(const ST_Node& a, const ST_Node& b) {
    return ST_Node(min(a.mps, b.mps), min(a.mns, b.mns));
}


int n;
ll a[maxN];

ST_Node st[maxN*4];

void apply_st(int i, ll val_p, ll val_n) {
    st[i].mps += val_p;
    st[i].mns += val_n;
    st[i].lazy_p += val_p;
    st[i].lazy_n += val_n;
}

void down_st(int i) {
    apply_st(2*i, st[i].lazy_p, st[i].lazy_n);
    apply_st(2*i + 1, st[i].lazy_p, st[i].lazy_n);
    st[i].lazy_p = st[i].lazy_n = 0;
}

void update_st(int u, int v, ll val_p, ll val_n, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return;
    
    if (u <= l && r <= v) {
        apply_st(i, val_p, val_n);
        return;
    }

    int m = (l + r)/2;
    down_st(i);
    update_st(u, v, val_p, val_n, 2*i, l, m);
    update_st(u, v, val_p, val_n, 2*i + 1, m + 1, r);

    st[i].mps = min(st[2*i].mps, st[2*i + 1].mps);
    st[i].mns = min(st[2*i].mns, st[2*i + 1].mns);
}

ST_Node get_st(int u, int v, int i = 1, int l = 0, int r = n - 1) {
    if (v < l || r < u)
        return ST_Node(maxVal, maxVal);
    
    if (u <= l && r <= v) 
        return st[i];

    int m = (l + r)/2;
    down_st(i);
    auto res = combine_st(get_st(u, v, 2*i, l, m), get_st(u, v, 2*i + 1, m + 1, r));

    st[i].mps = min(st[2*i].mps, st[2*i + 1].mps);
    st[i].mns = min(st[2*i].mns, st[2*i + 1].mns);

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        update_st(i, i, a[i] + i, a[i] - i);        
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            ll x;
            cin >> i >> x; --i;
            update_st(i, i, x - a[i], x - a[i]);
            a[i] = x;
        }
        else {
            int i;
            cin >> i; --i;
            cout << min(get_st(i, n - 1).mps - i, get_st(0, i).mns + i) << '\n';
        }
    }
}
