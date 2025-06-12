#include <iostream>
#include <stack>

using namespace std;

int *res, *record, *input;

int find(int left, int right, int data) { 
    int mid;
    while(left < right) {
        mid = (left+right)/2;
        if (res[mid] >= data) right = mid;
        else left = mid+1;
    }
    return right;
}

int main() {
    int n, idx=0; cin >> n;
    res = (int*)calloc(n+1, sizeof(int)), record=(int*)calloc(n+1, sizeof(int)), input = (int*)calloc(n+1, sizeof(int));
    cin >> res[0]; input[0] = res[0];
    for(int i=1;i<n;i++) {
        cin >> input[i];
        if (res[idx] < input[i]) {
            res[++idx] = input[i];
            record[i] = idx;
        }
        else {
            record[i] = find(0, idx, input[i]);
            res[record[i]] = input[i];
        }

        // for(int j=0;j<=idx;j++) cout << res[j] << ' ';
        // cout << '\n';
        // for(int j=0;j<=i;j++) cout << record[j] << ' ';
        // cout << '\n';
    }

    cout << idx+1 << '\n';
    stack<int> ans;

    for(int i=n-1;i>=0;i--) {
        if (record[i] == idx) {
            ans.push(input[i]);
            idx--;
        }
    }
    while(!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}