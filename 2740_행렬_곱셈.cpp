// https://www.acmicpc.net/problem/2740

#include <iostream>

using namespace std;

int n, m, k;
int mat1[102][102], mat2[102][102], ans[102][102];

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> mat1[i][j];
        }
    }
    cin >> m >> k;
    for(int i=0;i<m;i++) {
        for(int j=0;j<k;j++) {
            cin >> mat2[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            int product=0;
            for(int l=0;l<m;l++) {
                product += mat1[i][l]*mat2[l][j];
            }
            ans[i][j] = product;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}