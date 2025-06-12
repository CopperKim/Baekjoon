#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pll pair<long long, long long>
#define pllpq priority_queue<pll, vector<pll>, greater<pll>>
#define llpq priority_queue<long long, vector<long long>, greater<long long>>
using namespace std;

long long find(int N, long long D, pllpq ho) {
    long long ans=0, count=0;
    llpq start;

    while(!ho.empty()) {
        auto [curO, curH] = ho.top();
        // cout << curH << ' ' << curO << '\n';
        ho.pop();
        if (curH >= curO - D) {
            start.push(curH);
            count ++;
        }
        while(!start.empty() && start.top() < curO - D) {
            start.pop();
            count --;
        }

        ans = max(ans, count);
    }

    return ans;
}

int main() {
    int N; cin >> N;
    pllpq ho;
    for(int i=0;i<N;i++) {
        long long h, o; cin >> h >> o;
        if (h > o) swap(h, o);
        ho.push({o, h});
    }
    long long D; cin >> D;

    cout << find(N, D, ho);
}