// https://www.acmicpc.net/problem/11054

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int input[1003]={};
    int maxlen[1003]={}, revmaxlen[1003]={};
    for(int i=1;i<=n;i++) cin >> input[i];

    int inc[1003]={}, dec[1003]={};
    for(int i=1;i<=n;i++) {
        int max=0;
        for(int j=1;j<input[i];j++) {
            max = maxlen[max]<maxlen[j]?j:max;
        }
        maxlen[input[i]] = maxlen[max]+1;
        inc[i] = maxlen[input[i]];
    }
    for(int i=n;i>=1;i--) {
        int max=0;
        for(int j=1;j<input[i];j++) {
            max = revmaxlen[max]<revmaxlen[j]?j:max;
        }
        revmaxlen[input[i]] = revmaxlen[max]+1;
        dec[i] = revmaxlen[input[i]];
    }

    // for(int i=1;i<=n;i++) {
    //     cout << inc[i] << ' ';
    // }
    // cout << '\n';
    // for(int i=1;i<=n;i++) {
    //     cout << dec[i] << ' ';
    // }
    int res=0;
    for(int i=1;i<=n;i++) {
        res= max(inc[i]+dec[i], res);
    }

    cout << res-1;
}