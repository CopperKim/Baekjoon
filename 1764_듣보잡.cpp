#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    set<string> S;
    while(n--) {
        string str; cin >> str;
        S.insert(str);
    }
    vector<string> res; 
    while(m--) {
        string str; cin >> str;
        if (S.find(str) != S.end()) res.push_back(str); 
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto iter=res.begin();iter!=res.end();iter++) cout << *iter << '\n';
}