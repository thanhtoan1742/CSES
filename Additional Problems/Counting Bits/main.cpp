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

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;

int const NF = 55;

ll f[NF];


void make_f() {
    f[0] = 0;
    for (int i = 1; i < NF; ++i)
        f[i] = 2*f[i - 1] + (1ll << (i - 1));
}



ll solve(ll n) {
    if (n == 0)
        return 0;

    int l = 0;
    for (int i = 0; i < NF; ++i)
        if (n >= (1ll << i))
            l = i;

    ll res = f[l];
    ll c = n - (1ll << l);

    res += solve(c) + c;
    //cerr << n << " " << l << " " << res << "\n";

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    make_f();

    ll n;
    cin >> n;
    cout << solve(n + 1) << "\n";
    return 0;
}
