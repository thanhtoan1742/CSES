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
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 2e5 + 100;
const int base = 263;
const ll MOD = 1e9 + 7;

ll p[maxN];

struct st_node {
    ll val;
    int l, r;

    int len() {
        return r - l + 1;
    }
};

struct segment_tree {
    vector<st_node> st;
    vector<int> pos;

    void build(const string& s, int i, int l, int r) {
        st[i].l = l;
        st[i].r = r;

        if (l == r) {
            st[i].val = s[l];
            pos[l] = i;
            return;
        }

        int m = (l + r)/2;
        build(s, 2*i, l, m);
        build(s, 2*i + 1, m + 1, r);
        st[i].val = (st[2*i].val*p[r - m] + st[2*i + 1].val) % MOD;
    }

    ll get(int i, int l, int r) {
        if (r < st[i].l || st[i].r < l)
            return 0;
        
        if (l <= st[i].l && st[i].r <= r)
            return st[i].val*p[r - st[i].r] % MOD;

        ll res = get(2*i, l, r) + get(2*i + 1, l, r);
        st[i].val = (st[2*i].val*p[st[2*i + 1].len()] + st[2*i + 1].val) % MOD;
        return res % MOD;
    }

    segment_tree(const string& s) 
    : st(s.size()*4), pos(s.size()) {
        build(s, 1, 0, s.size() - 1);
    }

    void update(int idx, char c) {
        int i = pos[idx]; 
        st[i].val = c;
        i /= 2;
        while (i) {
            st[i].val = (st[2*i].val*p[st[2*i + 1].len()] + st[2*i + 1].val) % MOD;
            i /= 2;
        }
    }

    ll get(int l, int r) {
        return get(1, l, r);
    }
};

int n, m;
string a;

int ri(int i) {
    return n - i - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 

    cin >> n >> m;
    cin >> a;

    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1]*base % MOD;

    auto h = segment_tree(a);
    reverse(a.begin(), a.end());
    auto rh = segment_tree(a);

    while (m--) {
        int t;
        cin >> t;
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            if (h.get(l, r) == rh.get(ri(r), ri(l)))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            int i;
            char c;
            cin >> i >> c;
            --i;

            h.update(i, c);
            rh.update(ri(i), c);
        }
    }
}