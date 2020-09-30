#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
int a[maxN];
int x;

bool done[maxN];

int res;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    res = 0;
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        if (done[i])
            continue;
        ++res;
        done[i] = true;

        while (j > i && a[i] + a[j] > x)
            --j;
        if (j > i) {
            done[j] = true;
            --j;
        }
    }

    cout << res << '\n';
}