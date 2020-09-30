#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, s;
pair<int, int> a[maxN];

int main(int argc, char* argv[]) {
    // freopen(argv[1], "r", stdin)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);

    int j = n - 1;
    for (int i = 0; i < j; ++i) {
        while (j > i && a[i].first + a[j].first > s)
            --j;

        if (j > i && a[i].first + a[j].first == s) {
            cout << a[i].second << ' ' << a[j].second << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}