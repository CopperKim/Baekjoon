// https://www.acmicpc.net/problem/2565

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int input[503]={}, brr[503]={};

    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        input[a] = b;
    }

    for(int i=1;i<=500;i++) {
        if(input[i]==0) continue;
        int maxidx = 0;
        for(int j=1;j<i;j++) {
            if (input[j]<input[i] && brr[maxidx] < brr[j]) {
                maxidx = j;
            }
        }
        brr[i] = brr[maxidx] + 1;
    }

    int maxLines = 0;
    for(int i=1;i<=500;i++) {
        maxLines = max(maxLines, brr[i]);
    }
    cout << n - maxLines;
}