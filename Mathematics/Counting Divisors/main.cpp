#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxX = 1e6 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int fp[maxX];
int f[maxX];

void seive() {
    fp[1] = 1;
    for (int i = 2; i < maxX; ++i)
        if (!fp[i]) {
            for (int j = i; j < maxX; j += i)
                fp[j] = i;
        }
}

void DP() {
    f[1] = 1;
    for (int i = 2; i < maxX; ++i) {
        int u = i, c = 1;
        while (u % fp[i] == 0) {
            u /= fp[i];
            ++c;
        }

        f[i] = f[u]*c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    seive();
    DP();

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << f[x] << '\n';
    }
}
