#include <iostream>

using namespace std;

long long sum[100]; // sum[i] : 2^i-1 까지 1의 개수

long long count(long long a) {
    if (a == 0) return 0;
    long long bound = 1, exp=0;
    while(bound*2 <= a) {
        exp += 1;
        bound *= 2;
    }

    return (a - bound + 1 + count(a-bound) + sum[exp]);
}

int main() {
    long long a, b; cin >> a >> b;

    sum[0] = 0;
    for(int i=1;i<100;i++) {
        sum[i] = 2*sum[i-1] + (1LL << (i-1));
    }

    cout << count(b)-count(a-1);
}