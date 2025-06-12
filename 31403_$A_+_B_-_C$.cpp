#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a+b-c << '\n';
    int blen = 0, temp=1;
    while(temp <= b) {
        temp *= 10;
        a*=10;
    }
    cout << a+b-c;
}