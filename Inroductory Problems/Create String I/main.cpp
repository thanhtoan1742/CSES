#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

vector<string> ps;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do
    {
        ps.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ps.size() << '\n';
    for (int i = 0; i < ps.size(); ++i)
        cout << ps[i] << '\n';
}