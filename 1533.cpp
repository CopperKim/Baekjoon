#include <iostream>
#include <vector>

using namespace std;

const long long DIV = 1000003; 

long long N, S, E, T; 
long long input[11][11]; 
vector<vector<long long>> adj; 

vector<vector<long long>> matmul(vector<vector<long long>> &m1, vector<vector<long long>> &m2) {
    vector<vector<long long>> res(5*N, vector<long long>(5*N, 0));
    for(long long i=0;i<5*N;i++) {
        for(long long j=0;j<5*N;j++) {
            for(long long k=0;k<5*N;k++) res[i][j] += (m1[i][k] * m2[k][j])%DIV ; 
            res[i][j] %= DIV; 
        }
    }
    return res; 
}

vector<vector<long long>> powToT(long long pow) {
    if (pow == 1) return adj; 
    vector<vector<long long>> m = powToT(pow / 2), mm = matmul(m, m); 
    if (pow % 2 == 0) return mm;
    else return matmul(mm, adj); 
}

long long main() {
    cin >> N >> S >> E >> T; 
    adj = vector<vector<long long>>(5*N, vector<long long>(5*N, 0)); 
    for(long long i=0;i<N;i++) {
        string S; cin >> S; 
        for(long long j=0;j<N;j++) {
            input[i][j] = S[j] - '0'; 
        }
    }

    for(long long i=0;i<N;i++) {
        for(long long j=0;j<4;j++) adj[5*i+j+1][5*i+j] = 1; 
    }

    // adj[i][j] -> i to j edge exist with cost 1 
    // input[i][j] = 0 -> no edge 
    // input[i][j] = 1 -> 5*i to 5*j 
    // input[i][j] >= 2 -> 5*i to 5*j+input[i][j]-1 

    for(long long i=0;i<N;i++) {
        for(long long j=0;j<N;j++) {
            if (input[i][j] >= 1) adj[5*i][5*j+input[i][j]-1] = 1; 
        }
    }

    vector<vector<long long>> res = powToT(T); 

    cout << res[5*S-5][5*E-5] ; 
}