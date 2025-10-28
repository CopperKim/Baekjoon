#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    int fibo[41]; fibo[0]=0; fibo[1]=1;
    for(int i=2;i<=40;i++) fibo[i] = fibo[i-1] + fibo[i-2];

    while(t--) {
        int input; cin >> input;
        if (input == 0) {
            cout << "1 0" << '\n';
            continue;
        }
        cout << fibo[input-1] << ' ' << fibo[input] << '\n';
    }
}