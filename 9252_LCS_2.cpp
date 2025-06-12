#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001]={};
string S1; string S2;
    
void print(int i, int j) {
    if (i==0 || j==0) return; 
    if (S1[i-1] == S2[j-1]) {
        print(i-1, j-1);
        cout << S1[i-1];
        return;
    } else {
        dp[i][j-1]>dp[i-1][j]?print(i, j-1):print(i-1, j);
        return;
    }
}

int main() {
    cin >> S1 >> S2;
    for(int i=0;i<S1.length();i++) {
        for(int j=0;j<S2.length();j++) {
            if (S1[i] == S2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[S1.length()][S2.length()] << '\n';
    int i=S1.length(), j=S2.length();

    print(S1.length(), S2.length());
}