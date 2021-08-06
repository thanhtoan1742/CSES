#include <bits/stdc++.h>
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

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.push_back(bitset<30>(s).to_ulong());
    }

    int res = 100;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            res = min(res, __builtin_popcount(a[i] ^ a[j]));

    cout << res << "\n";
}
