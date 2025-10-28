#include <iostream>
#include <string>

using namespace std;

int main() {
    int alphabet[26]; for(int i=0;i<26;i++) alphabet[i] = -1;
    string S; cin >> S;

    for(int i=0;S[i];i++) {
        if (alphabet[S[i] - 'a'] == -1) alphabet[S[i]-'a'] = i;
    }

    for(int i=0;i<26;i++) {
        cout << alphabet[i] << ' ';
    }
}