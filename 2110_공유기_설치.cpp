// https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
vector<long long> house;

int eval(int minlen) {
    int count =1;
    int lastvalue = house[0];
    for(int i=1;i<n;i++) {
        if (house[i]-lastvalue >= minlen) {count++; lastvalue=house[i];}
    }
    return count;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        house.push_back(input);
    }
    sort(&house[0], &house[n]);

    // for(int i=1;i<house[n-1];i++) cout << eval(i) << ' ';
    // cout << '\n';
    
    int start=1, end=house[n-1]-house[0]+1;
    int mid;

    while(end > start) {
        mid = (start + end) / 2;
        if (eval(mid) < m) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    
    cout << start-1;
}