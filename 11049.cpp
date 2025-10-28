#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int *arr = (int*)calloc(n+2, sizeof(int));
    for(int i=1;i<=n;i++) {
        cin >> arr[i] >> arr[i+1]; // i번째 행렬 - arr[i] * arr[i+1]의 크기를 가짐
    }
    long long dp[501][501]={}; // dp[i][j] -> i번 행렬부터 j번 행렬까지 곱할 때 최소횟수, dp[1][n]을 구하면 됨됨
    for(int i=1;i<n;i++) dp[i][i+1] = arr[i] * arr[i+1] * arr[i+2]; // i번 행렬과 i+1번 행렬의 곱

    for(int space=2;space<=n;space++) { 
        for(int start=1;start<=n-space;start++) { // dp[start][start+space] 를 구할거임
            vector<int> costs;
            for(int term = start;term<start+space;term++) {
                // start부터 start+space 까지 행렬을 곱할 때, 이를 start부터 term번째까지 곱 * term+1부터 start+space번째까지의 곱 으로 생각
                // term 의 값은 start부터 start+space-1까지 가능함. 
                // 그 중 최솟값을 구하면 됨
                costs.push_back(dp[start][term] + dp[term+1][start+space] + arr[start] * arr[term+1] * arr[start+space+1]); 
            }
            dp[start][start+space] = *min_element(costs.begin(), costs.end());
        }
    }

    cout << dp[1][n];
}