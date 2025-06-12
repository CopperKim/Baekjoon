#include <iostream>
#include <string>

using namespace std;

int main() {
    string S; 
    while(1) {
        cin >> S;
        bool isPal=true;
        if (S[0]=='0') return 0;
        for(int i=0;S[i];i++) {
            if (S[i] != S[S.length()-i-1]) {
                isPal = false;
                break;
            }
        }
        isPal?cout << "yes\n":cout << "no\n";
    }
}