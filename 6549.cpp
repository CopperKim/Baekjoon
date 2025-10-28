// https://www.acmicpc.net/problem/6549

#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main() {
    while(1) {
        int n; cin >> n;
        if (n==0) return 0;
        long long maxValue=0;
        stack<pair<int, long long>> s;
        for(int i=0;i<n;i++) {
            long long input; cin >> input;
            int minidx = i;
            if (!s.empty()) {
                while(!s.empty() && s.top().second >= input) {
                    maxValue = max(maxValue, s.top().second*(i-s.top().first));
                    minidx = s.top().first;
                    s.pop();
                }
            }
            s.push({minidx, input});
        }
        if (!s.empty()) {
            while(!s.empty()) {
                maxValue = max(maxValue, s.top().second*(n-s.top().first));
                    s.pop();
                }
            }
        cout << maxValue << '\n';
    }
}