// https://www.acmicpc.net/problem/1013

#include <iostream>

using namespace std;

bool match(char* str, int idx) {
    if (str[idx] == '\0') return true;
    else if (str[idx]=='0' && str[idx+1]=='1') {
        return match(str, idx+2);
    }
    else if (str[idx]=='1' && str[idx+1]=='0') {
        idx+=2;
        if(str[idx]!='0') return false;
        while(str[idx]=='0') idx++;
        if(str[idx]!='1') return false;
        while(str[idx]=='1') idx++;
        if (match(str, idx)) return true;
        else if (str[idx-2]=='0') return false;
        else {
            return match(str, idx-1);
        }
    } else return false;
}

int main() {
    char input[205]; 
    for(int i=0;i<205;i++) input[i]=3;
    int n, idx; cin >> n;

    while(n--) {
        cin >> input;
        if (match(input, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}