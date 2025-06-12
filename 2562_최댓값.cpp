#include <iostream>

using namespace std;

int main() {
    int maxIdx=0, maxValue=0, input;
    for(int i=1;i<=9;i++) {
        cin >> input;
        if (max(maxValue, input) == input) {
            maxValue = input;
            maxIdx = i;
        }
    }
    cout << maxValue << '\n' << maxIdx;
}