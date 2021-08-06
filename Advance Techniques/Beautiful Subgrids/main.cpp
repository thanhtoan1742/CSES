#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

const int maxN = 3000 + 10;

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;

int n, m;
vector<bitset<maxN>> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a.emplace_back(s);
    }

    // cerr << n << " " << m << " " << k << "\n";
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j)
    //         cerr << bitset<k>(a[i][j]) << " " << a[i][j] << " ";
    //     cerr << "\n";
    // }

    ll res = 0;
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
        ll s = (a[i]&a[j]).count();
        res += s*(s - 1)/2;
    }
    cout << res << "\n";
}
