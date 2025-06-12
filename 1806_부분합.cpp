#include <iostream>

using namespace std;

int main() {
    long long n, s; cin >> n >> s;
    long long arr[100001]; 
    arr[0]=0; 
    for(long long i=0;i<n;i++) {
        long long input; cin >> input; 
        arr[i+1] = arr[i]+input;
        // cout << arr[i+1] << ' ';
    }
    
    if (arr[n] < s) {
        cout << 0;
        return 0;
    }
    
    long long i=1, j=1, minlen=n;

    while(j<=n) {
        if (arr[j]-arr[i-1] >= s) {
            // cout << i << ' ' << j << '\n';
            minlen = min(minlen, j-i+1);
            i++; 
        }
        else j++;
    }
    cout << minlen;
}