#include <bits/stdc++.h>

using namespace std;


string s;

int main() {
    cin >> s;
    int c = 1;
    int res = 0;
    for (int i = 1; i < s.size(); ++i)
        if (s[i] == s[i - 1]) 
            c++;
        else {
            res = max(res, c);
            c = 1;
        }

    res = max(res, c);
    cout << res  << '\n';
}