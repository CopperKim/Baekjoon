// https://www.acmicpc.net/problem/2630

#include <iostream>

using namespace std;

int n;
int paper[130][130];
int zerocount=0, onecount=0;

void dac(int r, int c, int paperlen) {
    for(int i=0;i<paperlen;i++) {
        for(int j=0;j<paperlen;j++) {
            if (paper[r+i][c+j] != paper[r][c]) {
                dac(r, c, paperlen/2);
                dac(r+paperlen/2, c, paperlen/2);
                dac(r, c+paperlen/2, paperlen/2);
                dac(r+paperlen/2, c+paperlen/2, paperlen/2);
                return;
            }
        }
    }
    if (paper[r][c] == 0) zerocount++;
    else onecount++;
    return;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {for(int j=0;j<n;j++) {cin >> paper[i][j];}}

    dac(0, 0, n);
    cout << zerocount << '\n' << onecount;
}