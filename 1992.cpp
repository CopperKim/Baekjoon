// https://www.acmicpc.net/problem/1992

#include <iostream>

using namespace std;

int n;
int map[66][66];

void QuadTree(int r, int c, int len) {
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if (map[r+i][c+j] != map[r][c]) {
                cout << '(';
                QuadTree(r, c, len/2);
                QuadTree(r, c+len/2, len/2);
                QuadTree(r+len/2, c, len/2);
                QuadTree(r+len/2, c+len/2, len/2);
                cout << ')';
                return;
            }
        }
    }
    cout << map[r][c];
    return;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    QuadTree(0, 0, n);
}