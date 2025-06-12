#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for(int i=1;i<n;i++) {
        int j = i;
        int temp=0;
        while(j > 0) {
            temp += j%10;
            j /= 10;
        }
        if (i + temp == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}