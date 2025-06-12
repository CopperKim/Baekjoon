// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

int n, i; 
int map[305][305];
pair<int, int> move[8] = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {2, 1}};
queue<pair<int, int>> Q;

bool isAvailable(pair<int, int> coord) {
    if (0 <= coord.first && coord.first <= i-1 && 0 <= coord.second && coord.second <= i-1) return true;
    return false;
}

void addNextPoint(pair<int, int> coord) {
    for(int i=0;i<8;i++) {
        pair<int, int> nextPoint = {coord.first+::move[i].first, coord.second+::move[i].second};
        if (isAvailable(nextPoint) && map[nextPoint.first][nextPoint.second] == 0) {
            map[nextPoint.first][nextPoint.second] = map[coord.first][coord.second]+1; 
            Q.push(nextPoint);
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        memset(map, 0, sizeof(map));
        queue<pair<int, int>> clear; swap(Q, clear);
        cin >> ::i; 
        pair<int, int> start, end; 
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        if (start.first == end.first && start.second == end.second) {
            cout << 0 << '\n';
            continue;
        }
        Q.push(start);
        while(!Q.empty() && map[end.first][end.second] == 0) {
            pair<int, int> curPoint = Q.front();
            Q.pop();
            addNextPoint(curPoint);
        }
        cout << map[end.first][end.second] << '\n';
    }
}