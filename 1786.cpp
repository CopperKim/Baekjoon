#include <iostream>
#include <vector>

using namespace std;

void kmp(vector<int> &pi, string &P) {
    int i=-1, j=0, n=P.length(); 
    pi[j] = i; 
    while(j < n) {
        if (i == -1 || P[i] == P[j]) {
            pi[++j] = ++i; 
        } else i = pi[i]; 
    }
}

int main() {
    string T, P; 
    getline(cin, T); 
    getline(cin, P); 

    vector<int> pi(P.length()+1);  

    kmp(pi, P); 

    int i=0, j=0; 
    int n=T.length(), m=P.length(); 
    vector<int> res; 

    while(i < n) {
        if (j == -1 || T[i] == P[j]) {
            i++; j++; 
        } else {
            j = pi[j]; 
        }

        if (j == m) {
            res.push_back(i-m+1); 
            j = pi[j]; 
        }
    }

    cout << res.size() << '\n'; 
    for(int val : res) cout << val << '\n'; 
}