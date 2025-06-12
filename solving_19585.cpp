#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Trie {
public :
    string data="";
    map<char, Trie*> Child;

    void addString(string S) {
        Trie *cur = this;
        for(int i=0;i<S.length();i++) {
            if (cur->Child.find(S[i]) == cur->Child.end()) cur->Child[S[i]] = new Trie();
            cur = cur->Child[S[i]];
        }
        cur->data = S;
    }

    void addReverseString(string S) {
        Trie *cur = this;
        for(int i=S.length()-1;i>=0;i--) {
            if (cur->Child.find(S[i]) == cur->Child.end()) cur->Child[S[i]] = new Trie();
            cur = cur->Child[S[i]];
        }
        cur->data = S;
    }

    vector<int> headSearch(string S) {
        Trie* cur = this;
        vector<int> res; 
        for(int i=0;i<S.length();i++) {
            char c = S[i];
            if (!cur->data.empty()) res.push_back(i); 
            if (cur->Child.find(c) == cur->Child.end()) return res;
            cur = cur->Child[c];
        } 
        if (!cur->data.empty()) res.push_back(S.length()); 
        return res;
    }
    vector<int> tailSearch(string S) {
        Trie* cur = this;
        vector<int> res; 
        for(int i=S.length()-1;i>=0;i--) {
            char c = S[i];
            if (!cur->data.empty()) res.push_back(i); 
            if (cur->Child.find(c) == cur->Child.end()) return res;
            cur = cur->Child[c];
        } 
        if (!cur->data.empty()) res.push_back(S.length()); 
        return res;
    }

    void BFSprint() {
        queue<Trie*> Q;
        Q.push(this);
        while(!Q.empty()) {
            Trie* cur = Q.front();
            Q.pop();
            for(auto p : cur->Child) {
                cout << p.first << ' ';
                Q.push(p.second);
            }
            cout << '\n';
        }
    }
};

int main() {
    int C, N; cin >> C >> N;
    Trie color = Trie(), name = Trie();

    for(int i=0;i<C;i++) {
        string input; cin >> input;
        color.addString(input);
    }
    for(int i=0;i<N;i++) {
        string input; cin >> input;
        name.addReverseString(input);
    }

    // for(int a : color.headSearch("redstring")) cout << a << ' ';
    // cout << '\n';
    // for(int a : name.tailSearch("redstring")) cout << a << ' ';
    // cout << '\n';

    int Q; cin >> Q;
    while(Q--) {
        bool found = false;
        string input; cin >> input;
        vector<int> head = color.headSearch(input), tail = name.tailSearch(input);
        for(auto h : head) {
            if (find(tail.begin(), tail.end(), h-1) != tail.end()) {
                cout << "Yes" << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << "No" << '\n';
    }
}

// 5 0
// red
// blue
// re
// redex
// rebl