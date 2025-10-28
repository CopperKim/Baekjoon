#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int L; 
char buf[200002]; 
vector<int> suffix(L); 

void sort() {
    
}

int main() {
    cin >> L; 
    cin >> buf; 
    for(int i=0;i<L;i++) suffix[i] = i ; 

    sort(); 

    // for(int a : suffix) {
    //     cout << a << ' '; 
    //     cout << buf+a << '\n'; 
    // }

    int maxLen = 0; 
   
    for(int i=0;i<L-1;i++) {
        // maxLen = max(maxLen, lcp(suffix[i], suffix[i+1])); 
    }

    cout << maxLen; 
}