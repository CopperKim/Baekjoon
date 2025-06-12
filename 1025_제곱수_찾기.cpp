// https://www.acmicpc.net/problem/1025

#include <iostream>
#include <cmath>

using namespace std;

bool isSqr(int n) {
    int root = static_cast<int>(sqrt(n));
    return root * root == n ? true : false;
}

int main() {
    int n, m;
    int map[10][10];
    int maxnum=-1;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int x=1;x<=n;x++) {
        for(int y=1;y<=m;y++) {
            if (isSqr(map[x][y])) maxnum = max(maxnum, map[x][y]);
            for(int dx=-x+1;dx<=n-x;dx++) {
                for(int dy=-y+1;dy<=m-y;dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int num=0, curx = x, cury = y;
                    while(1<=curx && curx<=n && 1<=cury && cury<=m) {
                        num = num*10 + map[curx][cury];
                        if (isSqr(num)) maxnum = max(maxnum, num);
                        curx += dx; 
                        cury += dy;
                    }
                }
            }
        }
    }

    cout << maxnum;
}