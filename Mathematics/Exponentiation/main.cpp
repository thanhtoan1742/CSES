#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int MOD = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

ll Pow(ll a, ll b) {
    if (b == 0)
        return 1;

    ll t = Pow(a, b/2);
    t = t*t % MOD;
    if (b&1)
        t = t*a % MOD;

    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << Pow(a, b) << '\n';
    }
}
