#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const long long mod = 1e9 + 7;

long long Power(long long a, int n) {
    if (n == 0)
        return 1;
    
    long long t = Power(a, n / 2);
    t = t * t % mod;
    if (n % 2)
        t = t * a % mod;
    return t;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << Power(2, n) << '\n';
}