#include <iostream>

using namespace std;

int main() {
    int ans=0; 
    int input; 
    for(int i=0;i<5;i++) {
        cin >> input;
        ans += input * input;
    }
    cout << ans%10;
}