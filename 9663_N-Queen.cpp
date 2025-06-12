// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>

using namespace std;

int n, count=0;

bool isAvailable(vector<int>& curCand, int curRow, int curColumn) {
    for(int i=0;i<curRow;i++) {
        int cmp = curCand.at(i);
        if (cmp == curColumn) {return false;}
        else if (abs(curRow-i) == abs(curColumn-cmp)) {return false;}
    }
    return true;
}

void dfs(int curRow, vector<int> curCand) {
    if (curRow == n) {
        count++;
        return;
    }
    for(int i=0;i<n;i++) {
        if(isAvailable(curCand, curRow, i)) {
            curCand.push_back(i);
            // for(vector<int>::iterator iter=curCand.begin();iter!=curCand.end();iter++) cout << *iter << ' ';            
            // cout << '\n';
            dfs(curRow+1, curCand); 
            curCand.pop_back();
        }
    }
}

int main() {    
    cin >> n;
    vector<int> curCand;
    dfs(0, curCand);
    cout << count;
}