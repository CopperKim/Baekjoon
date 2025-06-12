// https://www.acmicpc.net/problem/2842

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int house_count=0;
int pheight_idx=0;
int map[53][53]={};
bool house[53][53]={};
vector<int> post;
vector<int> height;

bool reachable(int min_idx, int max_idx) {
    queue<vector<int>> Q;
    Q.push(post);
    int visited_house=0;
    bool visited[53][53]={};
    vector<int> curPos;
    visited[post[0]][post[1]] = true;
    while(!Q.empty()) {
        curPos=Q.front();
        Q.pop();
        if (house[curPos[0]][curPos[1]]) visited_house++;
        if (visited_house == house_count) {
            return true;
        }
        for(int t=-1;t<=1;t++) {
            for(int y=-1;y<=1;y++) {
                if ((t != 0 || y != 0) && height[min_idx] <= map[curPos[0]+t][curPos[1]+y] && map[curPos[0]+t][curPos[1]+y] <= height[max_idx] && !visited[curPos[0]+t][curPos[1]+y]) {
                    visited[curPos[0]+t][curPos[1]+y] = true;
                    Q.push({curPos[0]+t, curPos[1]+y});
                }
            }
        }
    }
    if (visited_house == house_count) {
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    
    for(int r=1;r<=N;r++) {
        char* input = (char*)malloc((N+3)*sizeof(char));
        cin >> input;
        for(int c=1;c<=N;c++) {
            if(input[c-1] == 'P') post={r,c};
            else if (input[c-1] == 'K') {
                house_count++;
                house[r][c]=true;
            }
        }
        free(input);
    }

    for(int r=1;r<=N;r++) {
        for(int c=1;c<=N;c++) {
            cin >> map[r][c];
            height.push_back(map[r][c]);
        }
    }

    sort(height.begin(), height.end());
    height.erase(unique(height.begin(),height.end()), height.end());
    for(pheight_idx=0;height[pheight_idx]!=map[post[0]][post[1]];pheight_idx++);

    int min_idx=0, max_idx=pheight_idx;
    int min_piro = height.back();

    while(min_idx <= pheight_idx) {
        if(reachable(min_idx, max_idx)) {
            min_piro = min(min_piro, height[max_idx]-height[min_idx]); 
            min_idx++; 
        }
        else if (max_idx<height.size()) {max_idx++;}
        else break;
    }
    cout << min_piro;
}