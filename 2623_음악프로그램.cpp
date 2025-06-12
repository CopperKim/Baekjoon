#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int *inDegree = (int*)calloc(n+1, sizeof(int));
    vector<int> *G = (vector<int>*)calloc(n+1, sizeof(vector<int>));    
    
    for(int i=0;i<m;i++) {
        int k; 
        cin >> k;
        int lastinput=0, curinput=0;
        for(int i=0;i<k;i++) {
            cin >> curinput;
            if (lastinput != 0) {
                G[lastinput].push_back(curinput);
                inDegree[curinput]++;
            }
            lastinput = curinput;
        }
    }

    // for(int i=1;i<=n;i++) {
    //     for(int j : G[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i=1;i<=n;i++) cout << inDegree[i] << ' ';
    // cout << '\n';

    queue<int> Q; 
    for(int i=1;i<=n;i++) if (inDegree[i]==0) Q.push(i);
    int *res = (int*)calloc(n+1, sizeof(int));

    for(int i=1;i<=n;i++) {
        if (Q.empty()) {
            cout << 0;
            return 0;
        }
        int cur = Q.front();
        Q.pop();
        res[i] = cur;
        for(int j : G[cur]) {
            if (--inDegree[j] == 0) Q.push(j);
        }
    }

    for(int i=1;i<=n;i++) cout << res[i] << '\n';
}