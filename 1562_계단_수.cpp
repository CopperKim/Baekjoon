#include <iostream>
#define MAX 1000000000

using namespace std;

int arr[100][10][1024];

int main() {
    int n; cin >> n;

    for(int i=1;i<10;i++) arr[0][i][1 << i] = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<10;j++) {
            for(int k=0;k<1024;k++) {
                if (j>0) arr[i][j][k | (1 << j)] += arr[i-1][j-1][k];
                if (j<9) arr[i][j][k | (1 << j)] += arr[i-1][j+1][k];
                arr[i][j][k | (1 << j)] %= MAX;
            } 
        }
    }

    long long res = 0;
    for(int i=0;i<10;i++) res += arr[n-1][i][1023];
    res %= MAX;
    cout << res;
}