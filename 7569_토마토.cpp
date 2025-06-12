// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, h;
int map[103][103][103];
queue<vector<int>> Q;
vector<vector<int>> start;

int main() {
    cin >> m >> n >> h;
    int rotten=0, even=0;
    for(int k=1;k<=h;k++) {
        for(int j=1;j<=n;j++) {
            for(int i=1;i<=m;i++) {
                int input; cin >> input;
                if (input == 1) {map[i][j][k] = 0; Q.push({i, j, k}); }
                if (input == 0) map[i][j][k] = -1; 
                if (input == -1) {map[i][j][k] = -10; rotten++;}
            }
        }
    }
    while(!Q.empty()) {
        int i=Q.front()[0], j=Q.front()[1], k=Q.front()[2];
        Q.pop(); 
        even++;
        if (i+1 <= m && map[i+1][j][k] == -1) {map[i+1][j][k] = map[i][j][k] + 1; Q.push({i+1, j, k});}
        if (i-1 > 0 && map[i-1][j][k] == -1) {map[i-1][j][k] = map[i][j][k] + 1; Q.push({i-1, j, k});}
        if (j+1 <= n && map[i][j+1][k] == -1) {map[i][j+1][k] = map[i][j][k] + 1; Q.push({i, j+1, k});}
        if (j-1 > 0 && map[i][j-1][k] == -1) {map[i][j-1][k] = map[i][j][k] + 1; Q.push({i, j-1, k});}
        if (k+1 <= h && map[i][j][k+1] == -1) {map[i][j][k+1] = map[i][j][k] + 1; Q.push({i, j, k+1});}
        if (k-1 > 0 && map[i][j][k-1] == -1) {map[i][j][k-1] = map[i][j][k] + 1; Q.push({i, j, k-1});}
    } 

    int maxDay=0;

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=h;k++) {
                maxDay = max(maxDay, map[i][j][k]);
            }
        }
    }

    if (rotten + even != m*n*h) {cout << -1; return 0;}
    else cout << maxDay;
}