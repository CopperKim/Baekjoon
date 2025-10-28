#include <iostream>

using namespace std;

const int MAX = 52, MAXDIFF = 500000; 

int N; 
long long nums[MAX];
long long dp[MAX][MAXDIFF+1]; 

int main() {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> nums[i]; 

    for(int i=0;i<=N;i++) {
        for(int j=0;j<=MAXDIFF;j++) {
            dp[i][j] = -MAXDIFF; 
        }
    }

    dp[0][0] = 0; 

    for(int i=1;i<=N;i++) {
        for(int j=0;j<=MAXDIFF;j++) {
            if (dp[i-1][j] == -MAXDIFF) continue; 
            dp[i][j] = max(dp[i][j], dp[i-1][j]); 

            if (j + nums[i] <= MAXDIFF) {
                dp[i][j+nums[i]] = max(dp[i][j+nums[i]], dp[i-1][j]+nums[i]); 
            }

            if (j - nums[i] >= 0) {
                dp[i][j-nums[i]] = max(dp[i][j-nums[i]], dp[i-1][j]); 
            } else {
                dp[i][nums[i]-j] = max(dp[i][nums[i]-j], dp[i-1][j]+nums[i]-j); 
            }

            dp[i][nums[i]] = max(dp[i][nums[i]], nums[i]); 
        }
    }

    cout << ((dp[N][0]<=0) ? -1 : dp[N][0]); 
}