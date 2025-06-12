// https://www.acmicpc.net/problem/1854

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <climits>

using namespace std;

class State {
public :
    int pathLen, curCity;
    State(int pathLen, int curCity) {
        this->pathLen = pathLen;
        this->curCity = curCity;
    }

    bool operator<(const State& other) const {
        return this->pathLen > other.pathLen;
    }
};

class Road {
public : 
    int to, roadLen;
    Road(int to, int roadLen) {
        this->to = to;
        this->roadLen = roadLen;
    }
};

int main() {
    int n, m, k; 
    cin >> n >> m >> k;
    vector<Road> Roads[101];
    union a;
    
    for(int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        Roads[a].push_back(Road(b, c));
        Roads[b].push_back(Road(a, c));
    }

    int k_times[101];
    memset(k_times, k, (n+1)*sizeof(int));

    priority_queue<State> Q;
    Q.push(State(0, 1));

    while(!Q.empty()) {
        State curState = Q.top();
        Q.pop();
        
    }
}