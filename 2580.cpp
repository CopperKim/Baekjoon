// https://www.acmicpc.net/problem/2580

#include <iostream>
#include <vector>

using namespace std;

int map[11][11];
vector<vector<int>> blanks;
vector<int> blankFills;

bool isAvailable(int num, int count) {
    for(int x=1;x<=3;x++) {
        for(int y=1;y<=3;y++) {
            if (num == map[3*((blanks[count][0]-1)/3)+x][3*((blanks[count][1]-1)/3)+y]) return false;
        }
    }
    for(int i=1;i<=9;i++) {
        if(num == map[i][blanks[count][1]] || num == map[blanks[count][0]][i]) return false;
    }
    for(int i=0;i<count;i++) {
        if((blanks[count][0] == blanks[i][0] || blanks[count][1] == blanks[i][1]) && blankFills[i] == num) return false;
        if((blanks[count][0]-1)/3 == (blanks[i][0]-1)/3 && (blanks[count][1]-1)/3 == (blanks[i][1]-1)/3 && blankFills[i] == num ) return false;
    }
    return true;
}

void DFS(int count) { // count 인덱스의 blanks 칸을 채우는 중
    if (count == blanks.size()) { 
        for(int i=0;i<blanks.size();i++) {
            map[blanks[i][0]][blanks[i][1]] = blankFills[i];
        }
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=9;j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    for(int i=1;i<=9;i++) {
        if (isAvailable(i, count)) {
            blankFills.push_back(i);
            DFS(count + 1);
            blankFills.pop_back();
        }
    } 
}

int main() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) blanks.push_back({i, j});
        }
    }

    DFS(0);
}