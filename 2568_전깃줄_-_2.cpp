#include <iostream>
#include <queue>
#include <utility>

#define pii pair<int, int>

using namespace std;

int n;
priority_queue<pii> pq;
vector<int> LCS;

int search(int data) {
    int left = 1, right = LCS.size()-1;
    int mid;
    while(left < right) {
        mid = (left+right)/2;
        if (LCS[mid] < data) left = mid+1;
        else if (LCS[mid] > data) right = mid;
    }
    return right;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        pq.push({-a, b});
    }
    
    LCS.push_back(0);
    int *order = (int*)calloc(n+1, sizeof(int));
    vector<pii> lines;
    lines.push_back({0, 0});
    for(int i=1;i<=n;i++) {
        pii cur = pq.top();
        pq.pop();
        lines.push_back({-cur.first, cur.second});

        if (cur.second > LCS.back()) {
            LCS.push_back(cur.second);
            order[i]=LCS.size()-1;
        } 
        else {
            order[i] = search(cur.second);
            LCS[order[i]] = cur.second;
        }

        // for(int a : LCS) cout << a << ' ';
        // cout << '\n';
        // for(int j=1;j<=i;j++) cout << order[j] << ' ';
        // cout << '\n';
    }

    int len = LCS.size()-1;
    cout << n-len << '\n';
    priority_queue<int> ans;

    for(int i=n;i>0;i--) {
        if (order[i] == len) {
            len -- ;
        } else {
            ans.push(-lines[i].first);
        }
    }

    while(!ans.empty()) {
        cout << -ans.top() << '\n';
        ans.pop();
    }
}