#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int A[4001], B[4001], C[4001], D[4001];
    
    for(int i=0;i<n;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    vector<int> V; 
    for(int a=0;a<n;a++) for(int b=0;b<n;b++) V.push_back(A[a]+B[b]);
    sort(V.begin(), V.end());

    long long ans=0;
    for(int c=0;c<n;c++) {
        for(int d=0;d<n;d++) {
            int target = -(C[c]+D[d]);
            int l = lower_bound(V.begin(), V.end(), target) - V.begin(), h = upper_bound(V.begin(), V.end(), target) - V.begin();
            if (V[l] == target) ans += h-l;
        }
    }

    cout << ans;
}