#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];

long long res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) {
            res += max(0, a[i - 1] - a[i]);
            a[i] = max(a[i], a[i - 1]);
        }
    }

    cout << res << '\n';
}