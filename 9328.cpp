#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

// '.'는 빈 공간을 나타낸다.
// '*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
// '$'는 상근이가 훔쳐야하는 문서이다.
// 알파벳 대문자는 문을 나타낸다.
// 알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.

int h, w; 
vector<pair<int, int>> door[26];
char map[101][101];
bool key[26], visited[101][101];
queue<pair<int, int>> Q;

void bfs(pair<int, int> next, int &res) {
    if (map[next.first][next.second] == '.') { 
        visited[next.first][next.second] = true;
        Q.push(next);
        return;
    } 
    if (map[next.first][next.second] == '*') {
        visited[next.first][next.second] = true;
        return;
    }
    if (map[next.first][next.second] == '$') {
        visited[next.first][next.second] = true;
        Q.push(next);
        res++;
        return;
    }
    if (map[next.first][next.second] >= 'A' && map[next.first][next.second] <= 'Z') {
        if (key[map[next.first][next.second]-'A']) {
            visited[next.first][next.second] = true;
            Q.push(next);
        }
        else {
            door[map[next.first][next.second]-'A'].push_back(next); 
            // cout << "check " << map[next.first][next.second] << '\n';
        }
        return;
    }
    if (map[next.first][next.second] >= 'a' && map[next.first][next.second] <= 'z') {
        visited[next.first][next.second] = true;
        key[map[next.first][next.second] - 'a'] = true;
        Q.push(next);
        // cout << "get " << map[next.first][next.second] << '\n';
        for(pair<int, int> room : door[map[next.first][next.second] - 'a']) {
            // cout << "open " << map[room.first][room.second] << '\n';
            Q.push(room);
        }
        return;
    }
}

void test() {
    cin >> h >> w;
    for(int i=0;i<26;i++) door[i].clear();
    memset(key, false, sizeof(key));
    memset(visited, false, sizeof(visited));
    for(int i=0;i<h;i++) cin >> map[i];

    string keys; cin >> keys;
    if (keys[0] != '0') for(char c : keys) key[c-'a'] = true;

    int res=0;

    for(int i=0;i<h;i++) {
        bfs({i, 0}, res);
        bfs({i, w-1}, res);
    }
    for(int i=1;i<w-1;i++) {
        bfs({0, i}, res);
        bfs({h-1, i}, res);
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        // cout << cur.first << ' ' << cur.second << ' ' << map[cur.first][cur.second] << '\n';

        if (cur.first+1 < h && !visited[cur.first+1][cur.second]) {
            pair<int, int> next = {cur.first+1, cur.second};
            bfs(next, res);
        } 
        if (cur.first-1 >= 0 && !visited[cur.first-1][cur.second]) {
            pair<int, int> next = {cur.first-1, cur.second};
            bfs(next, res);
        } 
        if (cur.second+1 < w && !visited[cur.first][cur.second+1]) {
            pair<int, int> next = {cur.first, cur.second+1};
            bfs(next, res);
        } 
        if (cur.second-1 >= 0 && !visited[cur.first][cur.second-1]) {
            pair<int, int> next = {cur.first, cur.second-1};
            bfs(next, res);
        } 
    }

    // for(int i=0;i<26;i++) if (key[i]) cout << (char)('a'+i) << ' ';
    cout << res << '\n';
}

int main() {
    int T; cin >> T;
    while(T--) {
        test();
    }
    return 0;
}