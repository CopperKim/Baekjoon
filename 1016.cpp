// https://www.acmicpc.net/problem/1016

#include <iostream>

using namespace std;

int main() {
    long long min, max; cin >> min >> max;
    bool* nono = (bool*)calloc(max-min+2, sizeof(bool));
    for(long long i=2;i*i<=max;i++) {
        long long idx = i*i - (min-1) % (i*i) - 1;
        while(idx <= max-min) {
            nono[idx] = true;
            idx += i*i;
        }
    }
    long long count = 0;
    for(long long i=0;i<=max-min;i++) {
        if (nono[i] == false) {
            count ++ ;
        }
    }
    cout << count;
}