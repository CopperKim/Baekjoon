// https://www.acmicpc.net/problem/1780

#include <iostream>

using namespace std;

int n;
int map[2500][2500];
int minusonecount=0, zerocount=0, onecount=0;

void dac(int r, int c, int len) {
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if (map[r+i][c+j] != map[r][c]) {
                dac(r, c, len/3);
                dac(r+len/3, c, len/3);
                dac(r, c+len/3, len/3);
                dac(r+len/3, c+len/3, len/3);
                dac(r+2*len/3, c, len/3);
                dac(r, c+2*len/3, len/3);
                dac(r+2*len/3, c+2*len/3, len/3);
                dac(r+2*len/3, c+len/3, len/3);
                dac(r+len/3, c+2*len/3, len/3);
                return;
            }
        }
    }
    if (map[r][c] == -1) minusonecount++;
    else if (map[r][c] == 0) zerocount++;
    else onecount++;
    return;
} 

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }
    dac(0, 0, n);
    cout << minusonecount << '\n' << zerocount << '\n' << onecount;
}