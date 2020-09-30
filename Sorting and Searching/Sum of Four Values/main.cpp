#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e3 + 100;

int n;
long long x;
long long a[maxN];

long long b[maxN];

unordered_map<long long, pair<int, int>> s;

void print_res(int x, int y, int u, int v) {
    cout << x + 1 << ' ' << y + 1 << ' ' << u + 1 << ' ' << v + 1 << '\n';
}

bool precheck() {
    for (int i = 0; i < n; ++i)
        b[i] = a[i];
    sort(b, b + n, greater<long long>());
    if (n < 4 || b[0] + b[1] + b[2] + b[3] < x)
        return false;
    return true;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    s.reserve(n*n);

    if (!precheck()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) 
            if (s.find(x - a[i] - a[j]) != s.end()) {
                print_res(j, i, s[x - a[i] - a[j]].first, s[x - a[i] - a[j]].second);
                return 0;
            }

        for (int j = i + 1; j < n; ++j) 
            s[a[i] + a[j]] = {i, j};
    }
    cout << "IMPOSSIBLE\n";
}