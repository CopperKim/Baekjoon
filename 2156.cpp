// https://www.acmicpc.net/problem/2165

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    int* wine = (int*)calloc((n+2), sizeof(int));
    int* nolast = (int*)calloc((n+2), sizeof(int));
    int* onelast = (int*)calloc((n+2), sizeof(int));
    int* twolast = (int*)calloc((n+2), sizeof(int));

    for(int i=1;i<=n;i++) cin >> wine[i];
    
    nolast[1] = 0;
    nolast[2] = wine[1];
    onelast[1] = wine[1];
    onelast[2] = wine[2];
    twolast[1] = 0;
    twolast[2] = wine[1] + wine[2];

    for(int i=3;i<=n;i++) {
        nolast[i] = max((max(nolast[i-1], onelast[i-1])), twolast[i-1]);
        onelast[i] = nolast[i-1]+wine[i];
        twolast[i] = max(nolast[i-2], onelast[i-1]) + wine[i];
    }

    cout << max(max(nolast[n], onelast[n]), twolast[n]);
}