#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, a;
        cin >> n >> a;
        n--;

        int res = 0;
        while (n--) {
            cin >> a;
            res ^= a > 1;
        }

        if (!res)
            cout << "second\n";
        else
            cout << "first\n";
    }
}

// 0 L
// 1 L
// 2 L
// x 0 L
// x 1 W
// x 2 W
// x 3 W
// x 4 W
// x 0 1 W
// x 1 1 L
// x 0 2 W
// x 2 1 W
// x 1 2 L
// x 1 3 W
// x 3 1 W
// x 3 2 W
// x 3 3 W