#include <iostream>
#include <string.h>
#define INF 987654321987654321

using namespace std; 

// index : 고객 수, value : 가격

int main() {
    long long C, N; cin >> C >> N; // index, value
    long long dp[1100]; 
    for(long long i=0;i<=C;i++) dp[i] = INF; 
    dp[0] = 0; 

    for(long long i=0;i<N;i++) {
        long long cost, guest; cin >> cost >> guest ; 

        for(long long j = C;j >= 0; j--) {
            if (dp[j] == INF) continue; 
            long long k; 
            for(k = guest; j+k <= C ; k += guest) {
                dp[j+k] = min(dp[j] + k / guest * cost, dp[j+k]); 
            }

            dp[C] = min(dp[C], dp[j] + k / guest * cost ); 
        }
    }

    cout << dp[C] ; 
}