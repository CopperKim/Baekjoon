#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int size[6]; for(int i=0;i<6;i++) cin >> size[i];
    int t, p; cin >> t >> p;

    int count=0; 
    for(int i=0;i<6;i++) count += (size[i]+t-1)/t;
    cout << count << '\n';
    cout << n/p << ' ' << n%p; 
}