// https://www.acmicpc.net/problem/28324

#include <iostream>

using namespace std;

int main(){
    int i, n; cin >> n;
    long long maxnum, sum=0;
    long long* ans = (long long*)malloc(500001 * sizeof(long long));
    ans[n]=n;
    for(i=0;i<n;i++) {
        cin >> ans[i];
        ans[i]+=i;
    }
    maxnum = n;
    for(i=n;i>=0;i--){
        if(ans[i]>maxnum) ans[i]=maxnum;
        else if(ans[i]<maxnum) maxnum = ans[i];
        ans[i]-=i;
    }
    for(i=0;i<n;i++) sum+=ans[i];
    cout << sum;
    return 0;
}