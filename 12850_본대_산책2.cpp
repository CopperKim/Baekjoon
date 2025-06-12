#include <iostream>
#include <array>
#define MAX 1000000007
#define matrix array<array<long long, 8>, 8>

using namespace std;

// 정 전 미 신 한 진 학 형

matrix connection = { 
0, 1, 1, 0, 0, 0, 0, 0,
1, 0, 1, 1, 0, 0, 0, 0,
1, 1, 0, 1, 1, 0, 0, 0,
0, 1, 1, 0, 1, 1, 0, 0,
0, 0, 1, 1, 0, 1, 0, 1,
0, 0, 0, 1, 1, 0, 1, 0,
0, 0, 0, 0, 0, 1, 0, 1,
0, 0, 0, 0, 1, 0, 1, 0
};

matrix mul(matrix a, matrix b) {
    matrix result={};
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            for(int k=0;k<8;k++) result[i][j] += a[i][k]*b[k][j];
            result[i][j] %= MAX;
        }
    }
    return result;
}

matrix seung(long long D) {
    if (D == 1) {
        matrix res = connection;
        return res;
    }

    matrix res, mid = seung(D/2);

    res = mul(mid, mid);
    if (D%2 == 1) res = mul(res, connection);

    return res;
}

int main() {
    matrix res={};
    res[0][0] = 1;
    long long D; cin >> D;

    res = mul(res, seung(D));

    cout << res[0][0];
}