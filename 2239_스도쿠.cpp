#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[10][10];
vector<pair<int, int>> blank;

bool isOkay(int x, int y, int value) {
    // cout << x << ' ' << y << ' ' << value << '\n';
    for(int i=1;i<=9;i++) {
        if ((value == board[x][i] && i!=y) || (value == board[i][y] && i!=x)) return false;
    }

    int xstart = ((x-1)/3)*3, ystart = ((y-1)/3)*3;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            if (board[xstart+i][ystart+j]==value && (xstart+i != x || ystart+j != y)) return false;
        }
    }

    return true;
}

bool ans(int idx) {
    if (idx == blank.size()){
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=9;j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int curx=blank[idx].first, cury=blank[idx].second;
    for(int i=1;i<=9;i++) {
        if (isOkay(curx, cury, i)) {
            board[curx][cury] = i;
            if (ans(idx+1)) return true;
            board[curx][cury] = 0;
        } 
    }
    return false;
}

int main() {
    for(int i=1;i<=9;i++) {
        int input; cin >> input; 
        for(int j=9;j>=1;j--) {
            board[i][j] = input%10;
            input/=10;
        }
    }

    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            if (board[i][j] == 0) {
                blank.push_back({i, j});
                // cout << i << ' ' << j << '\n';
            }
        }
    }

    // cout << blank.size();

    ans(0);
}