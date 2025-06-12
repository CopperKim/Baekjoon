#include <iostream>

using namespace std;

int main () {
    int a, b, c; cin >> a >> b >> c;
    int n = a*b*c;
    int res[10]={};
    while(n>0) {
        res[n%10] ++;
        n /=10;
    }  
    for(int i=0;i<10;i++) cout << res[i] << '\n';
}