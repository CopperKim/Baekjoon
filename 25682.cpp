// https://www.acmicpc.net/problem/25682

#include <iostream>

using namespace std;

int n, m, k; 
char board[2001][2001];
int bsum[2001][2001];

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> &board[i][1];
        for(int j=1;j<=m;j++) {
            bsum[i][j]=bsum[i][j-1]+bsum[i-1][j]-bsum[i-1][j-1];
            if ((board[i][j] == 'B' && (i+j)%2 == 1) || (board[i][j] == 'W' && (i+j)%2 == 0)) bsum[i][j]++;
        }
    }

    int minsum=4000000, maxsum=0;

    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) { 
    //         cout << bsum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i=k;i<=n;i++) {
        for(int j=k;j<=m;j++) {
            int temp = bsum[i][j]-bsum[i-k][j]-bsum[i][j-k]+bsum[i-k][j-k];
            // cout << temp << ' ';
            minsum = min(minsum, temp);
            maxsum = max(maxsum, temp);
        }
        // cout << '\n';
    }
    cout << min(minsum, k*k-maxsum);
}