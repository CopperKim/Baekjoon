// https://www.acmicpc.net/problem/10830

#include <iostream>

using namespace std;

int n;
long long b;

int** mat() {
    int** res=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        res[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++) {cin >> res[i][j]; res[i][j]=res[i][j]%1000;}
    }
    return res;
}

int** matmul(int** x, int** y) {
    int** res=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        res[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++) {
            int product=0;
            for(int k=0;k<n;k++) {product += x[i][k]*y[k][j]; product=product%1000;}
            res[i][j]=product;
        }
    }
    return res;
}

int** daq(int** mat, long long jisu) {
    if (jisu == 1) return mat;
    int** m = daq(mat, jisu/2);
    if (jisu%2 == 0) return matmul(m, m);
    else return matmul(mat, matmul(m, m));
}

int main() {
    cin >> n >> b;
    int** a = mat();
    int** res = daq(a, b);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << res[i][j] << ' '; 
        }
        cout << '\n';
    }
}