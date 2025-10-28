#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x; cin >> n >> x;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        if (input < x) cout << input << ' ';
    }
}