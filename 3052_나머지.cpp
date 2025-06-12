#include <iostream>

using namespace std;

int main() {
    int res[42]={};
    for(int i=0;i<10;i++) {
        int input; cin >> input;
        res[input%42]++;
    }
    int count=0;
    for(int i=0;i<42;i++) {
        if (res[i] != 0) count++;
    }
    cout << count;
}