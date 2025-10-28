#include <iostream>
#include <algorithm>

using namespace std;

int n, idx, input;
int *arr;

int main () {
    cin >> n;
    arr = (int*)calloc(n+1, sizeof(int));
    
    for(int i=0;i<n;i++) {
        cin >> input;
        if (arr[idx] < input) arr[++idx] = input;
        else {
            int low=1, high = idx, mid;
            while(low <= high) {
                mid = (low+high+1)/2;
                if (arr[mid-1] < input && arr[mid] >= input) break;
                else if (arr[mid] >= input) high = mid-1;
                else low = mid+1;
            }
            arr[mid] = input;
        }
    }
    // for(int i=1;i<=idx;i++) cout << arr[i] << ' ';
    cout << idx;
}