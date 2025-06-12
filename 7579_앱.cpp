#include <iostream>

using namespace std;

long long min(long long a, long long b) {
    return a>b?b:a;
}

long long max(long long a, long long b) {
    return a>b?a:b;
}

int main() {
    long long n, m, totalcost=0; cin >> n >> m;
    long long byte[101], cost[101];
    for(int i=0;i<n;i++) cin >> byte[i];
    for(int i=0;i<n;i++) {cin >> cost[i]; totalcost += cost[i];}

    long long dp[10005]={}; 
    int mincost=totalcost;
    for(int i=0;i<n;i++) {
        for(int j=totalcost;j>=0;j--) {
            if (dp[j] != 0 || j==0) {
                if (dp[j] + byte[i] >= m) {
                    mincost = min(mincost, j+cost[i]);
                }
                dp[j+cost[i]] = (dp[j+cost[i]] == 0) ? dp[j] + byte[i]: max(dp[j+cost[i]], dp[j] + byte[i]);
            }
        }
        // for(int j=0;j<=totalcost;j++) cout << dp[j] << ' ';
        // cout << '\n';
    }

    cout << mincost;
}