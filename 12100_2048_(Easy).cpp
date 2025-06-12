#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int n;

class Node {
public :
    int rank;
    int **map;

    Node(int rank) {
        this -> rank = rank;
        this -> map = (int**)calloc(n, sizeof(int*));
        for(int i=0;i<n;i++) map[i] = (int*)calloc(n, sizeof(int));
    }

    void print() {
        cout << rank << '\n';
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Node UP() {
        Node newNode(rank+1); 
        for(int i=0;i<n;i++) {
            stack<pair<int, bool>> S; 
            for(int j=0;j<n;j++) {
                if (map[j][i] != 0) {
                    if (!S.empty() && S.top().first == map[j][i] && S.top().second == false ) {
                        S.pop();
                        S.push({2*map[j][i], true});
                    } else S.push({map[j][i], false});
                }
            }
            for(int j=S.size()-1;j>=0;j--) {
                newNode.map[j][i] = S.top().first;
                S.pop();
            }
        }
        return newNode;
    }

    Node DOWN() {
        Node newNode(rank+1);
        for(int i=0;i<n;i++) {
            stack<pair<int, bool>> S; 
            for(int j=n-1;j>=0;j--) {
                if (map[j][i] != 0) {
                    if (!S.empty() && S.top().first == map[j][i] && S.top().second == false ) {
                        S.pop();
                        S.push({2*map[j][i], true});
                        // cout << 2*map[j][i] << " true" << '\n';
                    } else {
                        S.push({map[j][i], false});
                        // cout << map[j][i] << " false" << '\n';
                    }
                }
            }
            for(int j=n-S.size();j<n;j++) {
                newNode.map[j][i] = S.top().first;
                S.pop();
            }
        }
        return newNode;
    }

    Node RIGHT() {
        Node newNode(rank+1);
        for(int i=0;i<n;i++) {
            stack<pair<int, bool>> S;
            for(int j=n-1;j>=0;j--) {
                if (map[i][j] != 0) {
                    if (!S.empty() && S.top().first == map[i][j] && S.top().second == false ) {
                        S.pop();
                        S.push({2*map[i][j], true});
                    } else S.push({map[i][j], false});
                }
            }
            for(int j=n-S.size();j<n;j++) {
                newNode.map[i][j] = S.top().first;
                S.pop();
            }
        }
        return newNode;
    }

    Node LEFT() {
        Node newNode(rank+1);
        for(int i=0;i<n;i++) {
            stack<pair<int, bool>> S;
            for(int j=0;j<n;j++) {
                if (map[i][j] != 0) {
                    if (!S.empty() && S.top().first == map[i][j] && S.top().second == false ) {
                        S.pop();
                        S.push({2*map[i][j], true});
                    } else S.push({map[i][j], false});
                }
            }
            for(int j=S.size()-1;j>=0;j--) {
                newNode.map[i][j] = S.top().first;
                S.pop();
            }
        }
        return newNode;
    }
};

int dfs(Node cur) {
    // cur.print();
    if (cur.rank == 5) {
        int maxValue=0; 
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) maxValue = max(maxValue, cur.map[i][j]);
        return maxValue;
    }
    
    return max(max(dfs(cur.UP()), dfs(cur.DOWN())), max(dfs(cur.RIGHT()), dfs(cur.LEFT())));
}

int main() {
    cin >> n;
    Node start(0); 
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> start.map[i][j];
    // start.print();
    // start.UP().print();
    // start.DOWN().print();
    // start.RIGHT().print();
    // start.LEFT().print();
    cout << dfs(start);
}