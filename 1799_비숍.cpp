#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int n; 
int res[2], map[11][11];
bool l[20], r[20];

void tracking(int row, int col, int count, int color) {
    if (col >= n) {
        row++;
        if (col % 2 == 0) col = 1;
        else col = 0;
    }
    if (row >= n) {
        res[color] = max(res[color], count);
        return;
    }
    if (map[row][col] && !l[row+col] && !r[n-1+row-col]) {
        l[row+col] = r[n-1+row-col] = 1;
        tracking(row, col+2, count+1, color);
        l[row+col] = r[n-1+row-col] = 0;
    }
    tracking(row, col+2, count, color);
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin >> map[i][j];
    }

    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);

    cout << res[0]+res[1];
}