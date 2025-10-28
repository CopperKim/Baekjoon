#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for(int& i : A) cin >> i;

    vector<int> ans(A);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(auto& val : A) {
        cout << distance(ans.begin(), lower_bound(ans.begin(), ans.end(), val)) << ' ';
    }
}