#include <iostream>
#define MAX 987654321

using namespace std;

int health(int a, int b) {
    if (a == b) return 1;
    if (a == 0) return 2;
    if (abs(a-b) == 1 || abs(a-b) == 3) return 3;
    if (abs(a-b) == 2) return 4;
}

int main() {
    int dp[5][5]={};
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) dp[i][j] = MAX;
    dp[0][0] = 0;

    int input, lastinput=0;

    while(1) {
        cin >> input; 

        if (input == 0) {
            int M=MAX;
            for(int i=0;i<5;i++) {
                for(int j=0;j<5;j++) {
                    M = min(M, dp[i][j]);
                }
            }
            cout << M;
            return 0;
        }

        int temp[5][5];
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) temp[i][j] = MAX;

        for(int i=0;i<5;i++) {
            temp[input][lastinput] = min(temp[input][lastinput], dp[i][lastinput]+health(i, input));
            temp[lastinput][input] = min(temp[lastinput][input], dp[lastinput][i]+health(i, input));

            temp[input][i] = min(temp[input][i], dp[lastinput][i]+health(lastinput, input));
            temp[input][i] = min(temp[input][i], dp[input][lastinput]+health(lastinput, i));

            temp[i][input] = min(temp[i][input], dp[lastinput][input]+health(lastinput, i));
            temp[i][input] = min(temp[i][input], dp[i][lastinput]+health(lastinput, input));
        }

        temp[input][input] = MAX;

        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                dp[i][j] = temp[i][j];
            }
        }

        // for(int i=0;i<5;i++) {
        //     for(int j=0;j<5;j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        lastinput = input;
    } 
}