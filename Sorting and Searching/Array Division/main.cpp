#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n, k;
long long a[maxN];

bool check(long long u) {
    long long s = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > u)
            return false;

        if (s + a[i] > u) {
            ++t;
            s = a[i];
        }
        else
            s += a[i];
    }

    return t + 1 <= k;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];   

    long long l = 0, h = (long long)(1e9)*maxN;
    while (l < h) {
        long long m = (l + h) / 2;
        if (!check(m))
            l = m + 1;
        else 
            h = m;
    }
    cout << h << '\n';
}
