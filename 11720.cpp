#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans =0;
    for(int i=0;i<n;i++) {
        int input; scanf("%1d", &input);
        ans += input;
    }
    cout << ans;
}