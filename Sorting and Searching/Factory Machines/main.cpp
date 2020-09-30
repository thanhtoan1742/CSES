#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, k;
long long a[maxN];

bool check(long long t) {
    long long p = 0;
    for (int i = 0; i < k; ++i) {
        if (p >= n)
            return true;
        p += t / a[i];
    }

    return p >= n;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    long long l = 0, r = 1e18 + 100;
    while (l < r) {
        long long m = (l + r) / 2;
        if (!check(m))
            l = m + 1;
        else
            r = m;
    }

    cout << r << '\n';
}