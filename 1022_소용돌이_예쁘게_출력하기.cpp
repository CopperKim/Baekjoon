// https://www.acmicpc.net/problem/1022

#include <iostream>

using namespace std;

int calcNum(int r, int c) {
    if (r==0 && c==0) return 1;
    int m = max(abs(r), abs(c));\
    if (r == m) return 4*m*m+3*m+1+c;
    else if (c == -m) return 4*m*m+m+1+r;
    else if (r == -m) return 4*m*m-m+1-c;
    else return 4*m*m-3*m+1-r;
}

int main() {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    int max1=calcNum(r1, c1), max2=calcNum(r1, c2), max3=calcNum(r2, c1), max4=calcNum(r2, c2);
    int maxlen = 0, maxnum = max(max(max(max1, max2), max3), max4);
    // cout << maxnum;
    for(maxlen=0;maxnum!=0;maxlen++) maxnum = maxnum / 10;
    // cout << maxlen;
    for(int i=r1;i<=r2;i++) {
        for(int j=c1;j<=c2;j++) {
            cout.width(maxlen);
            cout << calcNum(i, j) << ' ';
        }
        cout << '\n';
    }
}