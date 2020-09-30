#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;

template<typename T>
void print(T arg) { cout << arg; }

template<typename T, typename ...Ts>
void print(T arg, Ts ...args) {
    cout << arg << ' ';
    print(args...);
}

template<typename T>
void println(T arg) { cout << arg << '\n'; }

template<typename T, typename ...Ts>
void println(T arg, Ts ...args ) {
    cout << arg << ' ';
    println(args...);
}

template<typename T>
void read(T& arg) { cin >> arg; }

template<typename T, typename ...Ts>
void read(T& arg, Ts& ...args) {
    cin >> arg;
    read(args...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    read(n);
    if (n % 4 == 1 || n % 4 == 2)
        println("NO");
    else {
        println("YES");
        int start = 1;
        if (n % 4 == 3) {
            start = 4;

            println(n - n / 2);
            print(1, 2, ' ');   
        }
        else 
            println(n - n / 2);

        for (int i = start; i <= n; i += 4)
            print(i, i + 3, ' ');
        print('\n');

        println(n / 2);
        if (n % 4 == 3)
            print(3, ' ');
        for (int i = start; i <= n; i += 4) 
            print(i + 1, i + 2, ' ');

    }
}