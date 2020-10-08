#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
array<int, 3> a[maxN];

set<array<long long, 2>> s;
long long f[maxN];
long long res;

long long dp() {
    long long res = 0;

    s.insert({0ll, 0ll});
    for (int i = 0; i < n; ++i) {
        array<long long, 2> t = {a[i][0], 0ll};
        auto it = prev(s.lower_bound(t));
        f[i] = (*it)[1] + a[i][2];
        res = max(res, f[i]);

        t[0] = a[i][1];
        it = s.lower_bound(t);
        while (it != s.end() && (*it)[1] < f[i])
            it = s.erase(it);
        
        t[1] = res;
        s.insert(t);
    }

    return res;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a, a + n, [](array<int, 3> a, array<int, 3> b) {
        return a[1] < b[1];
    });

    cout << dp() << '\n';
}
