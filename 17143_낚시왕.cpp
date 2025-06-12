#include <iostream>
#include <queue>
#include <utility>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

using namespace std;

class Shark {
public :
    int speed, dir, size;
    bool moved;

    Shark(int __s, int __d, int __z) {
        speed = __s;
        dir = __d;
        size = __z;
        moved = false;
    }
};

int R, C, M; 
queue<Shark> **map;

int opposite(int dir) {
    if (dir == UP) return DOWN;
    if (dir == DOWN) return UP;
    if (dir == RIGHT) return LEFT;
    if (dir == LEFT) return RIGHT;
}

void moveShark(int r, int c) { // map[r][c]의 front shark를 이동시키는 함수.
    Shark cur = map[r][c].front();
    map[r][c].pop();

    int s = cur.speed;
    if (cur.dir == UP || cur.dir == DOWN) s %= 2*R-2;
    else s %= 2*C-2;

    switch(cur.dir) {
    case UP :
        if (s < r-1) r -= s;
        else if (s < r+R-2) {
            cur.dir = DOWN;
            r = s - r + 2;
        } else r = 2*R+r-s-2; // r - 1 + R - 1 + (s-r-R+2)
        break;
    case DOWN : 
        if (s < R-r) r += s;
        else if (s < 2*R-r-1) { // R - r + (s + r - R) = s
            cur.dir = UP;
            r = 2*R - s - r; // R - (s + r - R) 
        } else r = s + r - 2*R + 2;// 1 + (s-2*R+r+1)
        break;
    case RIGHT : 
        if (s < C-c) c += s;
        else if (s < 2*C-c-1) { // R - r + (s + r - R) = s
            cur.dir = LEFT;
            c = 2*C - s - c; // R - (s + r - R) 
        } else c = s + c - 2*C + 2;// 1 + (s-2*R+r+1)
        break;
    case LEFT :
        if (s < c-1) c -= s;
        else if (s < c+C-2) {
            cur.dir = RIGHT;
            c = s - c + 2;
        } else c = 2*C+c-s-2;
        break;
    }
    
    cur.moved = true;
    map[r][c].push(cur);

    // cout << r << ", " << c << ", size = " << cur.size << " moved \n";
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;
    map = new queue<Shark>*[R+1];
    for(int i=1;i<=R;i++) map[i] = new queue<Shark>[C+1];

    for(int i=0;i<M;i++) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        map[r][c].push({s, d, z});
    }

    // cout << "input end \n";

    int ans=0;

    for(int i=1;i<=C;i++) {
        int idx=1;
        while(idx <= R && map[idx][i].empty()) idx++;
        if (idx != R+1) {
            ans += map[idx][i].front().size;
            map[idx][i].pop();
        }

        // cout << "shark catch : " << idx << "\n";

        for(int r=1;r<=R;r++) {
            for(int c=1;c<=C;c++) {
                while(!map[r][c].empty() && map[r][c].front().moved == false) {
                    moveShark(r, c);
                }
            }
        }

        // cout << "shark moved \n";

        for(int r=1;r<=R;r++) {
            for(int c=1;c<=C;c++) {
                if (map[r][c].empty()) continue;
                Shark maxSize = map[r][c].front();
                map[r][c].pop();

                while(!map[r][c].empty()) {
                    Shark temp = map[r][c].front();
                    map[r][c].pop();
                    if (temp.size > maxSize.size) maxSize = temp;
                    // cout << temp.size << " dead \n";
                }

                if (!map[r][c].empty()) {
                    cout << 0 << '\n';
                    return 0;
                }
                
                maxSize.moved = false;
                map[r][c].push(maxSize);
            }
        }

        // for(int r=1;r<=R;r++) {
        //     for(int c=1;c<=C;c++) {
        //         if (map[r][c].empty()) cout << 0 << ' ';
        //         else cout << map[r][c].front().size << ' ';
        //     }
        //     cout << '\n';
        // }   
    }

    cout << ans << '\n';
}