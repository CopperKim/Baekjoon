#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int *disjoint;

int find(int a) {
    if (disjoint[a] == a) return a;
    else return disjoint[a] = find(disjoint[a]);
}

void merge(int a, int b) {
    a = find(a); 
    b = find(b);
    if (a>b) swap(a, b);
    disjoint[a] = b; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    disjoint = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++) disjoint[i] = i;

    int start, end, cost; 
    vector<pair<int, pair<int, int>>> e;
    for(int i=0;i<m;i++) {
        cin >> start >> end >> cost;
        e.push_back(make_pair(cost, make_pair(start, end)));
    }

    sort(e.begin(), e.end());

    vector<int> totalCost;

    for(int i=0;i<m;i++) {
        if (find(e[i].second.first) != find(e[i].second.second)) {
            merge(e[i].second.first, e[i].second.second);
            totalCost.push_back(e[i].first);
        }
    }

    int res=0; 
    for(int i=0;i<totalCost.size()-1;i++) res+= totalCost[i];
    cout << res;
    
}