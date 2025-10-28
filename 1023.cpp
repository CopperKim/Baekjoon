// https://www.acmicpc.net/problem/1023

#include <iostream>

using namespace std;

long long n, k; 
long long pow[51], memo[51][51]; // memo[i][j] : (이 i개 쓰였고, 남은 칸이 j개임
// memo[i][j] = memo[i+1][j-1] + memo[i+1][j-1];

int main() {
    cin >> n >> k;
    k++;
    
    pow[0] = 1;
    for(int i=1;i<=n;i++) {
        pow[i]=2*pow[i-1];
        memo[i][0] = 1;
    }

    for(int j=1;j<=n;j++) {
        memo[0][j] = pow[j-1] + memo[1][j-1];
        for(int i=1;i<=n-j;i++) {
            memo[i][j] = memo[i+1][j-1] + memo[i-1][j-1];
        }
    }

    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=n;j++) {
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if ((n%2==0 && memo[0][n] < k) || (n%2==1 && pow[n] < k)) {
        cout << -1;
        return 0;
    }

    int len = 0, leftCnt = 0;
    bool flag = (n%2==1);

    while(len < n) {
        if (flag) {
            if (k>pow[n-len-1]) {
                cout << ')';
                k -= pow[n-len-1];
            } else { 
                cout << '(';
            }
        } else { 
            if (k > memo[leftCnt+1][n-len-1]) {
                cout << ')';
                k -= memo[leftCnt+1][n-len-1];
                leftCnt--;
            } else {
                cout << '(';
                leftCnt++;
            }
        }

        if (!flag && leftCnt < 0) {
            flag = true;
        }

        len++;
    }

    return 0;
}