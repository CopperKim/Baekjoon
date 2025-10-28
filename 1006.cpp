#include <iostream>

using namespace std;

// 네 가지 케이스 - (1, N) 과 (N+1, 2N) 이 각각 하나로 커버쳐지는지 따라 나누고 
// a i -> i-1 번째 열까지 채워져 있고, i번째 열은 미결정 
// b i -> i-1 th column, lower block of ith column is determined, upper block is undetermined 
// c i -> reverse of bi 

// a_i = (a_i-1 + (1 or 2)), b_i-1 + 1, c_i-1 + 1
// b_i = a_i + 1, b_i-1 + 2, c_i-1 + (1 or 2)
// c_i = a_i + 1, b_i-1 + (1 or 2), c_i-1 + 2

// a_i-1, b_i-1, c_i-1 -> a_i -> b_i, c_i

// 1. x x -> a i+1     , initial : a0 = 0 b0 = 1 c0 = 1 
// 2. o x -> b i+1 + 1 , initial : a1 = 1 b1 = 2 c1 = (if e[0][0] + e[1][0] <= W then 1 else 2 )
// 3. x o -> c i+1 + 1 , initial : a1 = 1 b1 = (if e[0][1] + e[1][0] <= W then 1 else 2 ) c1 = 2
// 4. o o -> a i + 2   , initial : a1 = 0 b1 = 1 c1 = 1 

const int MAX = 10001, INF = 30000; 

int N, W; 
int e[MAX][2], a[MAX], b[MAX], c[MAX]; 

void solve(int start) {
    for(int i=start;i<=N;i++) {
        a[i] = min(b[i-1]+1, c[i-1]+1); 
        a[i] = min(a[i-1] + ( (e[i-1][0] + e[i-1][1]) <= W ? 1 : 2 ), a[i]); 
        if (i >= start+1 && e[i-2][0] + e[i-1][0] <= W && e[i-2][1] + e[i-1][1] <= W) a[i] = min(a[i], a[i-2] + 2);
        if (i <= N-1) { 
            b[i] = min(a[i]+1, b[i-1]+2); 
            b[i] = min(c[i-1] + (e[i][0] + e[i-1][0] <= W ? 1 : 2), b[i]); 
            c[i] = min(a[i]+1, c[i-1]+2); 
            c[i] = min(b[i-1] + (e[i-1][1] + e[i][1] <= W ? 1 : 2), c[i]);
        }
    }
}

int main() {
    int T; cin >> T; 

    while(T--) {
        
        cin >> N >> W; 

        for(int i=0;i<N;i++) {
            cin >> e[i][0]; 
        }
        for(int i=0;i<N;i++) {
            cin >> e[i][1]; 
        }
                
        for(int i=0;i<=N;i++) {
            a[i] = b[i] = c[i] = INF; 
        }
        a[0] = 0, b[0] = 1, c[0] = 1; 
        solve(1); 
        int res = a[N]; 

        if (e[0][0] + e[N-1][0] <= W) {       
            for(int i=0;i<=N;i++) {
                a[i] = b[i] = c[i] = INF; 
            }
            a[1] = 1, b[1] = 2, c[1] = (e[0][1] + e[1][1] <= W ? 1 : 2); 
            solve(2); 
            res = min(res, c[N-1] + 1); 
        }
        if (e[0][1] + e[N-1][1] <= W) {       
            for(int i=0;i<=N;i++) {
                a[i] = b[i] = c[i] = INF; 
            }
            a[1] = 1, b[1] = (e[0][0] + e[1][0] <= W ? 1 : 2), c[1] = 2; 
            solve(2); 
            res = min(res, b[N-1] + 1); 
        }
        if (e[0][0] + e[N-1][0] <= W && e[0][1] + e[N-1][1] <= W) {       
            for(int i=0;i<=N;i++) {
                a[i] = b[i] = c[i] = INF; 
            }
            a[1] = 0, b[1] = 1, c[1] = 1; 
            solve(2); 
            res = min(res, a[N-1] + 2); 
        }

        cout << res << '\n'; 
    }
}