#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
template<typename T>
using vec = vector<T>;
template<typename T, size_t N>
using ar = array<T, N>;

const ll MOD = 1e9 + 7;

ll prod(int begin, int end) {
    ll res = 1;
    for (int i = begin; i <= end; ++i)
        res = res*i % MOD;
    return res;
}

ll powM(ll a, ll b) {
    if (b == 0)
        return 1 % MOD;

    ll t = powM(a, b/2);
    t = t*t % MOD;
    if (b&1)
        t = t*a % MOD;
    return t;
}

ll catalan(int n) {
    // catalan(n) = (2n!)/(n!*(n + 1)!)
    // = ((n + 2)*(n + 3)*...*(2n))/(n!)

    ll a = prod(n + 2, 2*n);
    ll b = prod(2, n);
    return a * powM(b, MOD - 2) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n&1)
        cout << "0\n";
    else
        cout << catalan(n >> 1) << "\n";
}
