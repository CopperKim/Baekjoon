#include <iostream> 
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    
    int W, N; cin >> W >> N; 

    vector<int> inputs(N+1); 
    vector<pair<int, int>> sumOfTwo(400003, {-1, -1}); 

    for(int i=0;i<N;i++) {
        cin >> inputs[i]; 
    }

    for(int i=0;i<N-1;i++) {
        for(int j=i+1;j<N;j++) {
            if (sumOfTwo[inputs[i]+inputs[j]].first == -1) {
                sumOfTwo[inputs[i]+inputs[j]] = {i, j}; 

            }
        }
    }

    for(int i=0;i<N-1;i++) {
        for(int j=i+1;j<N;j++) {
            int sum = W-inputs[i]-inputs[j];
            if (sum < 0 || sum >= 400000 || sumOfTwo[sum].first < 0) continue; 
            if (sumOfTwo[sum].first != i && sumOfTwo[sum].first != j && sumOfTwo[sum].second != i && sumOfTwo[sum].second != j) {
                cout << "YES"; 
                return 0; 
            }
        }
    }

    cout << "NO"; 
    return 0; 
}