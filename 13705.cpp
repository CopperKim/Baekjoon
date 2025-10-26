#include <iostream> 
#include <cmath>

using namespace std;

#define N 30 

typedef __int128 LD; 
typedef __float128 LF; 
typedef long double lf; 

// 이분 탐색 
// 초기 범위는 C/A - 1 ~ C/A + 1

LF PI = 3.1415926535897932384626Q;

LF SIN(LF x) {
    x -= LD(x/PI)*PI;
    LF r=x, s=x, f=-x*x; 
    for(LF d=2;d<N;d+=2) {
        s *= f/(d*(d+1)); 
        r += s; 
    }
    return r; 
}

int main() {
    PI *= 2; 
    long double a, b, c; 
    LF A, B, C; 
    cin >> a >> b >> c;
    A=a, B=b, C=c;  
    LF U=1000000, D=0.5;
    LF s = (C - B) / A, e = (C + B) / A; 
    int t=80; 
    while (t--) {
        LF x = (s+e)/2;
        if (A*x+B*SIN(x) < C) s = x; else e = x;
    }

    printf("%Lf\n",lf(LD(U*e+D)/U));
}