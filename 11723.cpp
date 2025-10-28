#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    bool set[21]={};
    
    while(n--) {
        string S; 
        cin >> S;
        
        if (S == "all") {
            for(int i=1;i<=20;i++) set[i] = true;
        } else if (S == "empty") {
            for(int i=1;i<=20;i++) set[i] = false;
        } else {
            int input; cin >> input;
            if (S == "add") {
                set[input] = true;
            } else if (S == "remove") {
                set[input] = false;
            } else if (S == "check") {
                cout << set[input] << '\n';
            } else if (S == "toggle") {
                set[input] = !set[input];
            } 
        }
    }
}