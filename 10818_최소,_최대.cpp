#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;

    int maxValue=-10000000, minValue=10000000; 
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        if (max(maxValue, input) == input) maxValue = input;
        if (min(minValue, input) == input) minValue = input; 
    }

    cout << minValue << ' ' << maxValue;
}