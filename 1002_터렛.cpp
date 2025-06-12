// https://www.acmicpc.net/problem/1002

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        int a,s,d,f,g,h; cin >> a >> s >> d >> f >> g >> h;

        if (a==f && s == g && d == h) {
            cout << "-1\n";
            continue;
        }
        int distancesqred = (a-f)*(a-f)+(s-g)*(s-g);
        int y = (d+h)*(d+h);
        int u = (d-h)*(d-h);
        if (y < distancesqred) cout << "0\n";
        else if ( y == distancesqred ) cout << "1\n";
        else if ( u < distancesqred) cout << "2\n";
        else if (u == distancesqred) cout << "1\n";
        else cout << "0\n";
    }
}