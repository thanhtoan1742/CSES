#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 1e6 + 100;
const ll MOD = 1e9 + 7;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
ll f[maxN][2];

void dp() {
    f[1][0] = 1;
    f[1][1] = 1;

    for (int i = 2; i < maxN; ++i) {
        f[i][0] = (2*f[i - 1][0] + f[i - 1][1])%MOD;
        f[i][1] = (4*f[i - 1][1] + f[i - 1][0])%MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp();

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << (f[a][0] + f[a][1])%MOD << '\n';
    }
}