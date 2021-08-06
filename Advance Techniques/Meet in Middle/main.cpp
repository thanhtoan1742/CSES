#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;

vector<ll> gen(const vector<ll>& a) {
    int n = a.size();
    vector<ll> sa(1 << n);

    for (int msk = 0; msk < (1 << n); ++msk) {
        ll s = 0;
        for (int i = 0; i < n; ++i)
            if (gb(msk, i))
                s += a[i];

        sa[msk] = s;
    }

    sort(sa.begin(), sa.end());
    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll s;
    cin >> n >> s;
    vector<ll> a(n/2);
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
    vector<ll> b(n - n/2);
    for (int i = 0; i < b.size(); ++i)
        cin >> b[i];

    vector<ll> sa = gen(a);
    vector<ll> sb = gen(b);

    // for (auto s: sa)
    //     cout << s << " ";
    // cout << "\n";
    // for (auto s: sb)
    //     cout << s << " ";
    // cout << "\n";

    ll res = 0;
    for (int i = 0; i < sa.size(); ++i) {
        res += upper_bound(sb.begin(), sb.end(), s - sa[i])
            - lower_bound(sb.begin(), sb.end(), s - sa[i]);
        // cout << sa[i] << " " << s - sa[i] << " "  << res << "\n";
    }

    cout << res << "\n";
}
