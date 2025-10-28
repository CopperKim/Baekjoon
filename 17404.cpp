#include <iostream>
#define r 0
#define g 1
#define b 2
#define MAX 987654321

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int dp[3][3]={MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX}, next[3][3]={};

    cin >> dp[r][r] >> dp[g][g] >> dp[b][b];
    n--;
    while(n--) {
        int R, G, B; cin >> R >> G >> B;
        next[r][r] = min(dp[r][g], dp[r][b]) + R;
        next[g][r] = min(dp[g][g], dp[g][b]) + R;
        next[b][r] = min(dp[b][g], dp[b][b]) + R;
        
        next[r][g] = min(dp[r][b], dp[r][r]) + G;
        next[g][g] = min(dp[g][b], dp[g][r]) + G;
        next[b][g] = min(dp[b][b], dp[b][r]) + G;

        next[r][b] = min(dp[r][r], dp[r][g]) + B;
        next[g][b] = min(dp[g][r], dp[g][g]) + B;
        next[b][b] = min(dp[b][r], dp[b][g]) + B;

        for(int i=0;i<3;i++) for(int j=0;j<3;j++) dp[i][j] = next[i][j];
    }

    int ans=MAX;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if (i != j) ans = min(ans, dp[i][j]);
        }
    }
    cout << ans;
}