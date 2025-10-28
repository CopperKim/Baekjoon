// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <math.h>

using namespace std;

class mat {
public :
    long long a, b;
    long long c, d;
mat(int q, int w, int e, int r) {a=q; b=w;c=e;d=r;}
};

long long division=1000000007;
mat mit{1, 1, 1, 0};

mat matmul(mat first, mat second) {
    mat res{0, 0, 0, 0};
    
    res.a=(first.a*second.a+first.b*second.c)%division;
    res.b=(first.a*second.b+first.b*second.d)%division;
    res.c=(first.c*second.a+first.d*second.c)%division;
    res.d=(first.c*second.b+first.d*second.d)%division;
    return res;
}

mat power(long long jisu) {
    if (jisu==1) return mit;
    mat m = power(jisu/2);
    if (jisu%2==0) return matmul(m, m);
    return matmul(matmul(m, m), mit);
}

int main() {
    long long n; cin >> n;
    mat res=power(n);
    cout << res.b;
}