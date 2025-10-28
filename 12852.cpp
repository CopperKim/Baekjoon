// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <queue>
#include <vector>
// #include <algorithm>

using namespace std;

int main() {
    int N, M; cin >> N;
    if (N==1) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    M=N;
    int* visited = (int*)calloc(N+3, sizeof(int));
    visited[N] == -1;

    queue<int> Q;
    Q.push(N);

    while(visited[1] == 0) {
        M = Q.front();
        Q.pop();
        if( M % 3 == 0 && visited[M/3] == 0 ) {
            // cout << M/3 << ' ';
            Q.push(M/3);
            visited[M/3] = M;
        }
        if( M % 2 == 0 && visited[M/2] == 0 ) {
            // cout << M/2 << ' ';
            Q.push(M/2);
            visited[M/2] = M;
        }
        if (visited[M-1] == 0) {
            // cout << M-1 << ' ';
            Q.push(M-1);
            visited[M-1] = M;
        }
    }
    
    vector<int> result;

    int idx=1;
    while(idx != N) {
        result.push_back(idx);
        idx = visited[idx];
    }

    cout << result.size() << '\n';
    cout << N << ' ';
    for(int i=result.size()-1;i>=0;i--) {
        cout << result[i] << ' ';
    }
}