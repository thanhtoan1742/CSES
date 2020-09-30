#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

string a[10];

bool taken_main[10 + 10], taken_sub[10 + 10], taken_col[10];

int res;

void permutate(int i) {
    if (i == 8) {
        res++;
        return;
    }

    for (int j = 0; j < 8; ++j)
        if (a[i][j] != '*' && !taken_main[i + j] && !taken_sub[i - j + 8] && !taken_col[j]) {
            taken_col[j] = true;
            taken_main[i + j] = true;
            taken_sub[i - j + 8] = true;

            permutate(i + 1);

            taken_col[j] = false;
            taken_main[i + j] = false;
            taken_sub[i - j + 8] = false;
        }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 8; ++i)
        cin >> a[i];

    permutate(0);

    cout << res << '\n';
}