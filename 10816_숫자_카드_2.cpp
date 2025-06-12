#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    map<int, int> m;
    while(N--) {
        int input; cin >> input;
        m[input]++;
    }
    int M; cin >> M;
    while(M--) {
        int input; cin >> input;
        auto iter = m.find(input);
        if (iter == m.end()) cout << "0 ";
        else cout << iter->second << ' ';
    }
}