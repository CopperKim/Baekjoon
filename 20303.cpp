#include <iostream>
#include <vector>
#include <utility>
#define MAX 987654321

using namespace std;

int disjoint[30001];

int find(int idx) {
    if (idx == disjoint[idx]) return idx;
    else return disjoint[idx] = find(disjoint[idx]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    disjoint[a] = b;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    int c[30001]; 
    for(int i=1;i<=n;i++) {
        cin >> c[i];
        disjoint[i] = i;
    }
    
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    pair<int, int> arr[30001]={};

    for(int i=1;i<=n;i++) {
        arr[find(i)].first ++;
        arr[find(i)].second += c[i];
    }

    // for(int i=1;i<=n;i++) cout << arr[i].second << ' ';
    // cout << "\n";

    int dp[3001]={};

    for(int i=1;i<=n;i++) {
        if (arr[i].first == 0) continue;
        for(int j=k-1;j>0;j--) {
            if (dp[j] != 0 && j+arr[i].first < k) {
                dp[j+arr[i].first] = max(dp[j+arr[i].first], dp[j]+arr[i].second);
            }
        }
        dp[arr[i].first] = max(dp[arr[i].first], arr[i].second);
        // for(int j=0;j<k;j++) cout << dp[j] << ' ';
        // cout << '\n';
    }

    int M=0;
    for(int i=1;i<k;i++) M = max(M, dp[i]);

    cout << M;
}  