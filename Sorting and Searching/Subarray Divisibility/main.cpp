#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int c[maxN];

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int n;
    cin >> n;
    int s = 0;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        ++c[s];

        int a;
        cin >> a;
        s = (s + a%n + n)%n;
        res += c[s];
    }

    cout << res << '\n';
}
