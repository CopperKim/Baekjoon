#include <iostream>
#include <string>
#include <string.h>
#define MAX 9999

using namespace std;

int main() {
    string S; cin >> S;
    int len = S.size();
    int *pal = (int*)calloc(2*len-1, sizeof(int));
    // (i-pal[i])/2 ~ (i+pal[i])/2

    for(int i=0;i<2*len-1;i++) {
        if (i % 2 == 0) pal[i] = 0;
        else pal[i] = -1;
        while((i+pal[i]+2)/2 < len && (i-pal[i]-2)/2 >= 0 && S[(i+pal[i]+2)/2] == S[(i-pal[i]-2)/2]) pal[i]+=2;
        // cout << i << ' ' << pal[i] << '\n';
    }

    int *dp = new int[len]; // dp[i] : S[i] 까지 분할의 최소 횟수
    for (int i = 0; i < len; i++) dp[i] = MAX;

    for(int i=0;i<2*len-1;i++) {
        if ((i-pal[i])/2 == 0) dp[(i+pal[i])/2] = 1;
    }

    for(int i=1;i<len;i++) {
        // i-1 까지는 모두 분할 최소 횟수 계산 완료. 즉 dp[i-1] 까지는 건드릴 필요 없음
        // dp[i] 는 dp[0]부터 dp[i-1] 까지를 이용해 계산
        
        for(int j=i+1;j<=2*i;j++) {
            if ((j+pal[j])/2 >= i) {
                dp[i] = min(dp[i], dp[j-i-1]+1);
            }
        }
        
        // for(int j=0;j<len;j++) cout << dp[j] << ' ';
        // cout << '\n';
    }

    cout << dp[len-1];
}