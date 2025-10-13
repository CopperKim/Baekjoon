#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

// i+1 번째 사건은 경찰차 1 혹은 2가 처리한다. 
// dp[A][B] = 경찰차 1은 마지막으로 A, 경찰차 2는 마지막으로 B를 해결함 
// dp[i+1][C] 는 dp[i][C] + dist(i, i+1) 에 의해 갱신된다 
// dp[i+1][i] 는 dp[C][i] + dist(C, i+1) 에 의해 갱신된다 
// dp[C][i+1] 은 dp[C][i] + dist(i, i+1) 에 의해 갱신된다 
// dp[i][i+1] 은 dp[i][C] + dist(C, i+1) 에 의해 갱신된다 

typedef vector<pair<int, int>> Problem; 

const int INF = 987654321; 

int dist(Problem &P, int i, int j, int W) { // i th 사건과 j th 사건 사이 거리 반환 
    if (i == 0) return abs(P[0].first-P[j].first) + abs(P[0].second-P[j].second); 
    if (j == 0) return abs(P[i].first-P[W+1].first) + abs(P[i].second-P[W+1].second); 
    return abs(P[i].first-P[j].first) + abs(P[i].second-P[j].second); 
}

int fillNum(int x, int y, vector<int> &nums, vector<vector<pair<int, int>>> &parent) {
    if (x == 1 && y == 0) return nums[1] = 1; 
    if (x == 0 && y == 1) return nums[1] = 2; 
    
    if (min(x, y) == parent[x][y].first) nums[max(x, y)] = 2 ; 
    else nums[max(x, y)] = 1; 
    
    return fillNum(parent[x][y].first, parent[x][y].second, nums, parent); 
} 

void print(vector<vector<int>> vvi) {
    for(vector<int> vi : vvi) {
        for(int i: vi) cout << i << ' '; 
        cout << '\n'; 
    }
    
}

void DP(int &W, Problem &P, vector<vector<pair<int, int>>> &parent, vector<vector<int>> &dp) {
    dp[1][0] = dist(P, 0, 1, W);
    dp[0][1] = dist(P, 1, 0, W); 

    for(int cur=1;cur<W;cur++) {
        for(int i=0;i<=cur;i++) {
            if (dp[cur][i] != INF && dp[cur+1][i] > dp[cur][i] + dist(P, cur, cur+1, W)) {
                dp[cur+1][i] = dp[cur][i] + dist(P, cur, cur+1, W); 
                parent[cur+1][i] = {cur, i}; 
            }
            if (dp[i][cur] != INF && dp[cur+1][cur] > dp[i][cur] + dist(P, i, cur+1, W)) {
                dp[cur+1][cur] = dp[i][cur] + dist(P, i, cur+1, W); 
                parent[cur+1][cur] = {i, cur}; 
            }
            if (dp[i][cur] != INF && dp[i][cur+1] > dp[i][cur] + dist(P, cur, cur+1, W)) {
                dp[i][cur+1] = dp[i][cur] + dist(P, cur, cur+1, W); 
                parent[i][cur+1] = {i, cur};  
            }
            if (dp[cur][i] != INF && dp[cur][cur+1] > dp[cur][i] + dist(P, cur+1, i, W)) {
                dp[cur][cur+1] = dp[cur][i] + dist(P, cur+1, i, W); 
                parent[cur][cur+1] = {cur, i}; 
            }
        }
    }
    return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N; cin >> N;
    int W; cin >> W;

    Problem P(W+2); 
    P[0] = {1, 1}; 
    P[W+1] = {N, N}; 

    vector<vector<pair<int, int>>> parent(W+1, vector<pair<int, int>>(W+1, {0, 0})); 
    vector<vector<int>> dp(W+1, vector<int>(W+1, INF)); 

    for(int i=1;i<=W;i++) {
        cin >> P[i].first >> P[i].second; 
    }

    DP(W, P, parent, dp); 

    // print(dp); 
    
    pair<int, int> minCost = {W, W}; 
    for(int i=0;i<W;i++) {
        if (dp[i][W] != INF && dp[i][W] < dp[minCost.first][minCost.second]) minCost = {i, W}; 
        if (dp[W][i] != INF && dp[W][i] < dp[minCost.first][minCost.second]) minCost = {W, i}; 
    }
    // cout << minCost.first << ' ' << minCost.second << '\n'; 

    cout << dp[minCost.first][minCost.second] << '\n'; 

    vector<int> nums(W+2, 0);
    fillNum(minCost.first, minCost.second, nums, parent); 
    for(int i=1;i<=W;i++) cout << nums[i] << '\n' ; 
}