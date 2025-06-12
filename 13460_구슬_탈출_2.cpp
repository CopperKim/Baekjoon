#include <iostream>
#include <utility>

using namespace std;

int h, w;
char **map;

class Node {
public : 
    int rank; 
    pair<int, int> Red, Blue; 
    Node(int rank) {
        this -> rank = rank;
        if (rank == 0) {
            for(int i=0;i<h;i++) {
                cin >> map[i]; 
                // . # O R B
                for(int j=0;j<w;j++) {
                    if (map[i][j] == 'R') {Red = {i, j}; map[i][j] = '.';}
                    if (map[i][j] == 'B') {Blue = {i, j}; map[i][j] = '.';}
                }
            }
        }
    }

    Node copy() {
        Node newNode(rank+1);
        newNode.Red = this->Red; newNode.Blue = this->Blue;
        return newNode;
    }
    
    void move(pair<int, int> dir) {
        while(1) { // R, B가 구멍에 빠지는 경우, Red, Blue 는 {h, w} 로 수정.
            if (Red.first == h && Blue.first == h) break;

            if ( (Red.first == h || (map[Red.first+dir.first][Red.second+dir.second] == '#' || (Red.first+dir.first == Blue.first && Red.second+dir.second == Blue.second))) && \
            (Blue.first == h || (map[Blue.first+dir.first][Blue.second+dir.second] == '#' || (Blue.first+dir.first == Red.first && Blue.second+dir.second == Red.second)))) break;

            if (Red.first != h) {
                if (map[Red.first+dir.first][Red.second+dir.second] == '.') {
                    Red.first += dir.first;
                    Red.second += dir.second;
                } else if (map[Red.first+dir.first][Red.second+dir.second] == 'O') {
                    Red = {h, w};
                } 
            }
            if (Blue.first != h) {
                if (map[Blue.first+dir.first][Blue.second+dir.second] == '.') {
                    Blue.first += dir.first;
                    Blue.second += dir.second;
                } else if (map[Blue.first+dir.first][Blue.second+dir.second] == 'O') {
                    Blue = {h, w};
                }
            }
            
            // cout << Red.first << ' ' << Red.second << '\n' << Blue.first << ' ' << Blue.second << '\n';
        }
        
        // cout << dir.first << ' ' << dir.second << " : \n";
        // print();
    }

    void print() {
        cout << rank << '\n';
        cout << Red.first << ' ' << Red.second << '\n' << Blue.first << ' ' << Blue.second << '\n';
        // for(int i=0;i<h;i++) {
        //     for(int j=0;j<w;j++) {
        //         cout << map[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
};

int dfs(Node cur) {
    if (cur.rank == 11) return 11;
    if (cur.Red.first == h) {
        if (cur.Blue.first == h) {
            return 11;
        } else return cur.rank;
    }

    Node UP=cur.copy(), DOWN=cur.copy(), RIGHT=cur.copy(), LEFT=cur.copy();
    UP.move({-1, 0});
    DOWN.move({1, 0});
    RIGHT.move({0, 1});
    LEFT.move({0, -1});
    return min(min(dfs(UP), dfs(DOWN)), min(dfs(RIGHT), dfs(LEFT)));
}

int main() {
    cin >> h >> w;
    map = (char**)calloc(h, sizeof(char*));
    for(int i=0;i<h;i++) { map[i] = (char*)calloc(w+1, sizeof(char)); }    
    Node start(0);
    // start.print();
    // cout << "-----------------\n";
    // start.move({0, 1});
    // cout << "-----------------\n";
    // start.move({1, 0});
    int res = dfs(start);
    if (res == 11) cout << -1;
    else cout << res;
}