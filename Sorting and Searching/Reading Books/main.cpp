#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long ma = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        maximize(ma, a);
        s += a;
    }

    cout << max(2*ma, s) << '\n';
}