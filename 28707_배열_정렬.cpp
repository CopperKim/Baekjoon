#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main () {
    int N; cin >> N;

    vector<int> A(N);
    for(int& i : A) cin >> i;

    int M; cin >> M;
    
    vector<tuple<int, int, int>> edges(M);
    for(auto& [l, r, c] : edges) {
        cin >> l >> r >> c;
        l--; r--;
    }

    map<vector<int>, int> dist;
    priority_queue<pair<int, vector<int>>> pq;
    pq.push({0, A});
    
    while(!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] >= -cost) {
            for(auto [l, r, c] : edges) {
                swap(now[l], now[r]);
                if (!dist.count(now) || dist[now] > -cost + c) {
                    pq.push({-(dist[now] = -cost + c), now});
                }
                swap(now[l], now[r]);
            }
        }
    }

    sort(A.begin(), A.end());

    if (dist.count(A)) cout << dist[A];
    else cout << -1;
    return 0;
}