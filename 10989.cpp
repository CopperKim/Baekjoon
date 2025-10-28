#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    
    int arr[10001]={};
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        arr[input] ++;
    }

    for(int i=0;i<10001;i++) {
        for(int j=0;j<arr[i];j++) cout << i << '\n';
    }
}