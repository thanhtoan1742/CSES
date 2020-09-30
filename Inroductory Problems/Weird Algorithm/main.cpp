#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    do {
        cout << n << ' ';
        if (n == 1)
            break;
        if (n & 1)
            n = n * 3 + 1;
        else 
            n /= 2;
    }
    while (true);
}