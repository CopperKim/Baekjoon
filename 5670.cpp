#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

// Trie 에 저장 후, dfs로 각 노드의 cost 계산 후 sum 

class Trie {
public :
// char node; 
string value; 
map<char, Trie> child; 

    Trie() { 
        value = ""; 
    }

    void append(const string &S, int cur=-1) {
        if (cur + 1 == (int)S.size()) {
            value = S; 
            return; 
        }
        
        if (child.find(S[cur+1]) == child.end()) {
            Trie newT; 
            child[S[cur+1]] = newT; 
        }
        child[S[cur+1]].append(S, cur+1); 
        return; 
    }

    int ans(int len) {
        int size = child.size(); 
        if (value.empty()) { 
            if (size == 1) {
                return child.begin()->second.ans(len); 
            }
            int res = 0;  
            for(auto &iterator : child) {
                res += iterator.second.ans(len+1); 
            }
            return res; 
        }
        
        if (size == 0) {
            return len; 
        } else {
            int res = len; 
            for(auto &iterator : child) {
                res += iterator.second.ans(len+1); 
            }
            return res; 
        }
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    cout.setf(std::ios::fixed);
    cout << setprecision(2); 
    int n; 

    while(cin >> n) {
        Trie root = {}; 

        for(int i=0;i<n;i++) {
            string S; cin >> S; 
            root.append(S); 
        }
        
        double sum = 0.0;
        for (auto &kv : root.child) {
            sum += kv.second.ans(1); 
        }

        cout <<  + ((double)sum / n) << '\n'; 
    }
}