#include <iostream>
#include <utility>

#define pll pair<long long, long long>

using namespace std;

int CCW(pll p1, pll p2, pll p3) {
    long long res = (p1.first*p2.second-p2.first*p1.second + p2.first*p3.second-p3.first*p2.second + p3.first*p1.second-p1.first*p3.second) ;
    if (res > 0) return 1;
    else if (res == 0) return 0;
    else return -1;
}

int main() {
    pair<pll, pll> l1, l2;
    
    cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
    cin >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;
    
    int p1p2 = CCW(l1.first, l1.second, l2.first)*CCW(l1.first, l1.second, l2.second);
    int p3p4 = CCW(l2.first, l2.second, l1.first)*CCW(l2.first, l2.second, l1.second);

    if (p1p2 <= 0 && p3p4 <= 0) {
        if (p1p2 == 0 && p3p4 == 0 ) {
            if (l1.first > l1.second) swap(l1.first, l1.second);
            if (l2.first > l2.second) swap(l2.first, l2.second);
            
            cout << (l2.first <= l1.second && l1.first <= l2.second) << '\n';
            return 0;
        }
        else cout << 1 << '\n';
        return 0;
    }

    cout << 0 << '\n';
    return 0;   
}