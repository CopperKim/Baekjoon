#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<int> dijkstra(int start, int n, vector<pair<int, int>>* graph) {
    vector<int> res(n+1, INF);
    res[start] = 0;
    priority_queue<pair<int, int>> pq; // -cost, node를 저장하고 있음.
    pq.push({0, start});

    while(!pq.empty()) {
        int cost = -pq.top().first, node = pq.top().second;
        pq.pop();

        for(pair<int, int> edge : graph[node]) {
            int next_node = edge.first;
            int next_cost = cost + edge.second;

            if (next_cost < res[next_node]) {
                res[next_node] = next_cost;
                pq.push({-next_cost, next_node});
            }
        }
    }

    return res;
}

int main() {
    int n, m; cin >> n >> m;
    int start; cin >> start;

    vector<pair<int, int>> *G = new vector<pair<int, int>>[n+1];
    // 유향 가중치 그래프
    bool *visited = new bool[n+1];
    // 다음 노드, 코스트

    for(int i=0;i<m;i++) {
        int s, e, c; cin >> s >> e >> c;
        G[s].push_back({e, c});
    }
    
    vector<int> dist = dijkstra(start, n, G);

    for(int i=1;i<=n;i++) {
        if (dist[i]==INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}   