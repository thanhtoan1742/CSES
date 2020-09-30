#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

int n;
string s;

int c[256];

void solve() {
    n = s.length();
    for (int i = 0; i < n; ++i)
        c[s[i]]++;

    bool have_odd = false;
    for (int i = 'A'; i <= 'Z'; ++i)
        if (c[i] % 2 != 0) {
            if (have_odd) {
                s = "NO SOLUTION";
                return;
            }
            have_odd = true;
        }

    int l = 0;
    int r = n - 1;
    for (int i = 'A'; i <= 'Z'; ++i)
        if (c[i] % 2 == 0) {
            while (c[i] > 0) {
                s[l] = s[r] = i;
                c[i] -= 2;
                l++; 
                r--;
            }
        }

    for (int i = 'A'; i <= 'Z'; ++i)
        if (c[i] % 2 == 1) {
            while (c[i] > 1) {
                s[l] = s[r] = i;
                c[i] -= 2;
                l++;
                r--;
            }
            s[l] = i;
        }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    solve();
    cout << s << '\n';
}