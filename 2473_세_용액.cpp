#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    long long *arr = (long long*)calloc(n+1, sizeof(long long));
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    int minf=0, mins=1, mint=n-1;
    for(int first=0;first<n-2;first++) {
        int second = first+1, third = n-1;
        while(second < third) {
            if (abs(arr[first]+arr[second]+arr[third]) < abs(arr[minf]+arr[mins]+arr[mint])) {
                minf=first;
                mins=second;
                mint=third;
            }
            if (arr[first]+arr[second]+arr[third] < 0) {
                second++;
            } else {
                third--;
            } 
        }
    }
    cout << arr[minf] << ' ' << arr[mins] << ' ' << arr[mint];
}