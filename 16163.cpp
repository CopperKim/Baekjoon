#include <bits/stdc++.h>

using namespace std;

// manacher algorithm 

const long long MAX = 2000000; 

long long N; 
char S[MAX+1]; 
char buf[2*MAX+1]; 
long long pal[2*MAX+1]; 

void find() {
    long long bound = 0; 
    long long axis = 0; 
    for(long long i=0;i<N;i++) { // 각 iteration 에 pal[i-1] 은 완성되어 있다고 가정 
        long long r = 0; 

        if (i <= bound) { 
            r = min(bound - i, pal[2*axis - i]); 
        }

        while (i - r >= 0 && i + r <= N-1) {
            if (buf[i-r] != buf[i+r]) break; 
            r++; 
        }
        r--; 

        pal[i] = r; 
        if (bound < i + r) {
            axis = i; 
            bound = i + r; 
        }
    }
}

int main() {
    cin >> S; 
    buf[0] = '#'; 
    for(long long i=0;S[i]!=0;i++) {
        buf[2*i+1] = S[i] ; 
        buf[2*i+2] = '#'; 
        if(S[i+1] == '\0') N=2*i+3, buf[2*i+3]='\0'; 
    }

    find(); 

    // cout << buf << '\n'; 
    // for(long long i=0;i<N;i++) cout << pal[i]; 
    // cout << '\n'; 

    long long res=0; 

    for(long long i=1;i<N-1;i++) {
        res += (pal[i]+1)/2; 
    }

    cout << res; 
}