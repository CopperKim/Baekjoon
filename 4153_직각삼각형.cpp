#include <iostream>

using namespace std;

int main() {
    while(1) {
        int a, b, c; cin >> a >> b >> c;
        if (a==0 && b==0 && c==0) return 0;
        if (b<a) swap(a, b);
        if (c<b) swap(b, c);
        (a*a+b*b==c*c)?cout << "right\n":cout << "wrong\n";
    }
}