#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int largest_digit(int n) {
    int res = 0;
    while (n > 0) {
        maximize(res, n%10);
        n /= 10;
    }
    return res;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    while (n) {
        n -= largest_digit(n);
        ++res;
    }
    cout << res << '\n';
}
