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

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ar<int, 2>> res;

void toh(int n, int s = 1, int t = 3) {
    if (n == 0)
        return;

    toh(n - 1, s, 6 - s - t);
    res.push_back({s, t});
    toh(n - 1, 6 - s - t, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    toh(n);

    cout << res.size() << '\n';
    for (auto m: res)
        cout << m[0] << ' ' << m[1] << '\n';
}
