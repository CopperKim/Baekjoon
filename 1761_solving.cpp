#include <iostream>
#include <vector>

using namespace std;

int N, M;
int *tree;
vector<int> *parent; // parent[x][k] : x 노드의 2^k 번째 부모까지의 거리
pair<int, pair<int, int>> *edges; // cost , (start, end) 



int main() {
    cin >> N;
    tree = new int[N+1];
    parent = new vector<int>[N+1];

    
}