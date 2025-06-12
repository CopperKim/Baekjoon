// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K; 
    cin >> N;
    cin >> K;
    bool apple[105][105] = {};
    deque<vector<int>> snake;
    snake.push_back({1, 1});
    for(int i=0;i<K;i++) {
        int a, b; cin >> a >> b;
        apple[a][b] = true;
    }
    int L, time = 0; cin >> L;
    int dir = 1; // 0 : 위 1 : 오 2 : 아래 3 : 좌
    for(int i=0;i<L;i++) {
        int X;
        char C; 
        cin >> X >> C;
        X = X-time;
        for(int i=0;i<X;i++) {
            switch(dir) {
                case 0 : {snake.push_back({snake.back()[0]-1, snake.back()[1]}); break;}
                case 1 : {snake.push_back({snake.back()[0], snake.back()[1]+1}); break;}
                case 2 : {snake.push_back({snake.back()[0]+1, snake.back()[1]}); break;}
                case 3 : {snake.push_back({snake.back()[0], snake.back()[1]-1}); break;}
            }
            bool bak = false;
            if (1>snake.back()[0] || snake.back()[0] > N || 1 > snake.back()[1] || snake.back()[1] > N ) bak = true;
            for(int j=0;j<snake.size()-1;j++) {
                if (snake.back() == snake.at(j)) {cout << 'c'; bak = true;}
            }
            ++time;
            if (bak) {
                ::cout << time;
                return 0;
            }
            if (!apple[snake.back()[0]][snake.back()[1]]) snake.pop_front(); 
            else apple[snake.back()[0]][snake.back()[1]]=false;
            // ::cout << snake.back()[0] << ' ' << snake.back()[1] << ' ';
            // ::cout << snake.front()[0] << ' ' << snake.front()[1] << '\n';
        }
        if (C == 'D') dir = (dir + 1) % 4;
        else if (C == 'L') dir = (dir + 3) % 4;
        // cout << dir;
    }
    for(int i=0;i<N;i++) {
        switch(dir) {
            case 0 : {snake.push_back({snake.back()[0]-1, snake.back()[1]}); break;}
            case 1 : {snake.push_back({snake.back()[0], snake.back()[1]+1}); break;}
            case 2 : {snake.push_back({snake.back()[0]+1, snake.back()[1]}); break;}
            case 3 : {snake.push_back({snake.back()[0], snake.back()[1]-1}); break;}
        }
        bool bak = false;
        if (1>snake.back()[0] || snake.back()[0] > N || 1 > snake.back()[1] || snake.back()[1] > N ) bak = true;
        for(int j=0;j<snake.size()-1;j++) {
            if (snake.back() == snake.at(j)) {cout << 'c'; bak = true;}
        }
        ++time;
        if (bak) {
            break;
        }
        if (!apple[snake.back()[0]][snake.back()[1]]) snake.pop_front(); 
        else apple[snake.back()[0]][snake.back()[1]]=false;
        // ::cout << snake.back()[0] << ' ' << snake.back()[1] << ' ';
        // ::cout << snake.front()[0] << ' ' << snake.front()[1] << '\n';
    }
    cout << time;
    return 0;
}