#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string S;
    for(int i=0;i<n;i++) {
        cin >> S;
        int start=0;
        int score=0;
        for(int i=0;S[i];i++) {
            if (i!=0 && S[i]=='O' && S[i-1]=='X') start = i;
            if (S[i] == 'O') score += i - start + 1;
        }
        cout << score << '\n';
    }
}