// https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int Mod=1000000000;
    long long int** stair = (long long int**)malloc(10*sizeof(long long int*));
    for(int i=0;i<10;i++) {
        stair[i] = (long long int*)malloc((n+3)*sizeof(long long int));
        stair[i][1] = 1;
    }
    stair[0][1] = 0;

    for(int i=2;i<=n+1;i++){
        stair[0][i] = stair[1][i-1]%Mod;
        stair[9][i] = stair[8][i-1]%Mod;
        for(int j=1;j<=8;j++) {
            stair[j][i]=stair[j-1][i-1]+stair[j+1][i-1];
            stair[j][i] = stair[j][i] % Mod;
        }
    }

    long long int result =0;
    for(int i=0;i<10;i++){
            result += stair[i][n];
            result = result%Mod;
            }
            cout << result%Mod;
}