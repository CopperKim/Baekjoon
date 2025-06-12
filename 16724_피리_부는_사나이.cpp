#include <iostream>
#include <utility>

using namespace std;

pair<int, int> disjoint[1001][1001];

pair<int, int> find(pair<int, int> p) {
    if (disjoint[p.first][p.second] == p) return p;
    else return disjoint[p.first][p.second] = find(disjoint[p.first][p.second]);
}

void merge(pair<int, int> p1, pair<int, int> p2) { // p1의 parent 를 p2로
    p1 = find(p1);
    p2 = find(p2);
    disjoint[p1.first][p1.second] = p2;
}

int main() {
    int n, m;
    cin >> n >> m;
    char map[1001][1001];
    for(int i=0;i<n;i++) cin >> map[i];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            disjoint[i][j] = {i, j};
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            pair<int, int> next = {i, j};
            switch(map[i][j]) {
                case 'U' : 
                    next.first --;
                    break;
                case 'D' :
                    next.first ++;
                    break;
                case 'R' :
                    next.second ++;
                    break;
                case 'L' :
                    next.second --;
                    break;
            }
            merge({i, j}, next);
        }
    }

    bool visited[1001][1001]={};

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[find({i, j}).first][find({i, j}).second] = true;

    int ans=0;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if (visited[i][j]) ans++;

    cout << ans;
}