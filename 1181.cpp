#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string S1, string S2) {
    if (S1.length() < S2.length()) return true;
    if (S1.length() == S2.length()) return S1<S2;
    return false;
}

int main () {
    int n; cin >> n;
    vector<string> V; 
    for(int i=0;i<n;i++) {
        V.push_back(string());
        cin >> V[i];
    }
    sort(V.begin(), V.end(), comp);
    for(int i=0;i<n-1;i++) {
        if (V[i] != V[i+1]) cout << V[i] << '\n';
    }
    cout << V[n-1];
}