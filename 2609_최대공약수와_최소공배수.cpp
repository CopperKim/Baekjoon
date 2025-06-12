#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int gcd=1, lcd=a;
    for(int i=1;i<=a;i++) {
        if ((b/i)*i==b && (a/i)*i==a) gcd=i;
    }
    lcd = a*b/gcd;
    cout << gcd << '\n' << lcd;
}