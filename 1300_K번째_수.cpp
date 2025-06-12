// https://www.acmicpc.net/problem/1300

#include <iostream>

using namespace std;

long long n, k; 

long long eval(long long m) {
    long long count=0;
    for(long long i=1;i<=n;i++) {
        count += min(n, m/i);
    }
    return count;
}

void BS(long long start, long long end) {
    long long mid = (start + end) / 2;
    if (eval(mid-1) < k && k <= eval(mid)) {
        cout << mid << '\n';
        return;
    } else if (eval(mid) < k) {
        BS(mid, end);
    } else if (eval(mid-1) >= k) {
        BS(start, mid);
    }
}

int main() {
    cin >> n >> k;

    BS(1, n*n+1);
    // for(n=1;n<=10;n++) {
    //     cout << n << '\n';
    //     for(k=1;k<=n*n;k++) {
    //         cout << k << ' ';
    //         BS(1, n*n+1);
    //     }
    // }
}