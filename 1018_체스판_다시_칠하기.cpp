#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char board[51][51];
    int a[51][51]={};
    for(int i=1;i<=n;i++) cin >> &board[i][1];
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if ((board[i][j] == 'W' && (i+j)%2==0) || (board[i][j] == 'B' && (i+j)%2==1)) a[i][j] += 1; 
            // cout << a[i][j] << ' ';
        }
        // cout << '\n';
    }
    
    int minVal=n*m, maxVal = 0;
    for(int i=8;i<=n;i++) {
        for(int j=8;j<=m;j++) {
            maxVal = max(maxVal, a[i][j] - a[i-8][j] - a[i][j-8] +a[i-8][j-8]);
            minVal = min(minVal, a[i][j] - a[i-8][j] - a[i][j-8] +a[i-8][j-8]);
        }
    }
    // cout << minVal << maxVal << '\n';
    cout << min(minVal, 64-maxVal);
}