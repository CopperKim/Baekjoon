// https://www.acmicpc.net/problem/11053

#include <iostream>

using namespace std;

int main() {
    int a[1006]={};
    int n; cin >> n;

    for(int i=1;i<=n;i++) {
        int input; cin >> input;
        int max=0;
        for(int j=1;j<input;j++) {
            max = (a[j]>max)?a[j]:max;
        }
        a[input] = max+1;
    }
    int max=0;
    for(int j=1;j<=1000;j++) {
        max = (a[j]>max)?a[j]:max;
    }
    cout << max;
}