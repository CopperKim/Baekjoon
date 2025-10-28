// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> money;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        money.push_back(input);
    }
    int res=0;
    for(vector<int>::iterator iter=money.end()-1;iter!=money.begin()-1;iter--) {
        res += k / *iter;
        k = k % *iter;
    }
    cout << res;
}