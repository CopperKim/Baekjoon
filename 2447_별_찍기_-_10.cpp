// https://www.acmicpc.net/problem/2447

#include <iostream>

using namespace std;

int map[6500][6500];

void recursive(int r, int c, int n) {
    if (n==1) {
        map[r][c] = 1;
        return;
    } 
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if (j!=1 || i != 1) recursive(r+n*i/3, c+n*j/3, n/3);
        }
    }
}

int main() {
    int n; cin >> n;
    recursive(0, 0, n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (map[i][j] == 1) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}