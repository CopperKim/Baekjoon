// https://www.acmicpc.net/problem/1629

#include <iostream>

using namespace std;

long long a, b, c;

long long ans(int jisu) {
    if (jisu==1) return a%c;
    long long temp = ans(jisu/2);
    if (jisu%2==0) {
        return temp*temp%c;
    } else return (temp*temp%c)*a%c;
}

int main() {
    cin >> a >> b >> c;
    cout << ans(b);
}