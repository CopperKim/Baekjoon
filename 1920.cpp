#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int *arr = (int*)calloc(n, sizeof(int));
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    int m; cin >> m;
    for(int i=0;i<m;i++) {
        int input; cin >> input;
        cout << binary_search(&arr[0], &arr[n], input) << '\n';
    }
}