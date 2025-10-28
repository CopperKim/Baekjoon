#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> members[201];
    for(int i=0;i<n;i++) {
        int input1; cin >> input1;
        string input2; cin >> input2;
        members[input1].push_back(input2);
    }

    for(int i=0;i<=200;i++) {
        for(string S : members[i]) {
            cout << i << ' ' << S << '\n';
        }
    }
}