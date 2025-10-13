#include <iostream> 
#include <climits>
#include <vector> 
#include <queue> 
#include <algorithm>
#include <utility> 

using namespace std;

typedef vector<vector<pair<int, int>>> Graph; // {next node, cost} cost == -1 when disabled 

const int INF = INT_MAX/2; 

// void printGraph(int &V, Graph &G) {
//     for(int i=0;i<V;i++) {
//         vector<pair<int, int>> edges = G[i]; 
//         for(pair<int, int> edge : edges) {
//             cout << "from node " << i << " to " << edge.first << ", cost : " << edge.second << '\n'; 
//         }
//     }
// }

int dijkstra(int start, int V, int end, vector<vector<int>> &parent, Graph &G) {
    priority_queue<pair<int, int>> pq; 
    pq.push({0, start}); 
    vector<int> distTo(V, INF); 
    distTo[start] = 0; 

    while(!pq.empty()) {
        int cost = -pq.top().first; 
        int cur = pq.top().second; 
        pq.pop(); 
        if (cost != distTo[cur]) continue; 

        for(pair<int, int> &edge : G[cur]) {
            if (edge.second == -1) continue; 
            int next_node = edge.first; 
            int next_cost = cost + edge.second; 

            if (next_cost == distTo[next_node]) {
                parent[next_node].push_back(cur); 
            } else if (next_cost < distTo[next_node]) {
                distTo[next_node] = next_cost; 
                parent[next_node].clear(); 
                parent[next_node].push_back(cur); 
                pq.push({-next_cost, next_node}); 
            }
        }
    }

    return distTo[end]; 
}

void delete_shortest_paths(int &end, int &V, vector<vector<int>> &parent, Graph &G) {

    queue<int> delete_paths; 
    vector<bool> visited(V, false);  
    delete_paths.push(end); 

    while(!delete_paths.empty()) {
        int cur = delete_paths.front(); 
        delete_paths.pop(); 

        for(int before : parent[cur]) {
            for(pair<int, int> &edge : G[before]) { // before -> cur 간선을 없앤다. 
                if (edge.first == cur) { 
                    edge.second = -1; 
                    break;
                } 
            }
            if (!visited[before]) { 
                visited[before] = true;
                delete_paths.push(before);
            } 
        }
    }
}

void almost_shortest_path(int V, int E) {

    int start, end; cin >> start >> end; 

    Graph G(V), G_r(V); 
    vector<vector<int>> parent(V); // 최단 경로 역추적을 위한 부모 노드 저장 
    
    for(int i=0;i<E;i++) {
        int s, e, c; cin >> s >> e >> c;
        G[s].push_back({e, c}); 
    }

    // cout << 
    dijkstra(start, V, end, parent, G); 
    //  << '\n'; 

    // printGraph(V, G); 

    delete_shortest_paths(end, V, parent, G); 

    // printGraph(V, G); 

    // parent 초기화 해줘야 두번째 dijkstra에서 절지 않는다 - gpt 

    vector<vector<int>> pparent(V); 

    int res = dijkstra(start, V, end, pparent, G); 
    cout << ((res == INF) ? -1 : res) << '\n'; 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    while(1) {
        int a, b; cin >> a >> b;
        if (a == 0 && b == 0) return 0; 
        almost_shortest_path(a, b); 
    }
}