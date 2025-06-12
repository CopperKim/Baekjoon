#include <iostream>
#include <vector>
#include <utility>

#define pll pair<long long, long long>
#define x first
#define y second 

using namespace std;

class line {
public : 
    pll p1, p2;

    line(long long x1, long long y1, long long x2, long long y2) {
        p1 = {x1, y1};
        p2 = {x2, y2};
    }
};

vector<line> V;

long long CCW(pll p1, pll p2, pll p3) {
    return ((p1.x-p2.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p1.y-p2.y));
}

bool overlap(line l1, line l2) {
    long long o1 = CCW(l1.p1, l1.p2, l2.p1)*CCW(l1.p1, l1.p2, l2.p2), o2 = CCW(l2.p1, l2.p2, l1.p1)*CCW(l2.p1, l2.p2, l1.p2);
    if (o1 == 0 && o2 == 0) {
        if (l1.p1 > l1.p2) swap(l1.p1, l1.p2);
        if (l2.p1 > l2.p2) swap(l2.p1, l2.p2);
        return l2.p1 <= l1.p2 && l1.p1 <= l2.p2; 
    }
    
    else return (o1 <= 0 && o2 <= 0);
}

long long *disjoint;

long long find(long long a) {
    if (disjoint[a] == a) return a;
    else return disjoint[a] = find(disjoint[a]);
}

void merge(long long a, long long b) {
    a = find(a);
    b = find(b);
    disjoint[a] = b;
}

int main() {
    long long n; cin >> n;
    disjoint = (long long*)calloc(n+1, sizeof(long long));
    for(long long i=0;i<n;i++) disjoint[i] = i;

    for(long long i=0;i<n;i++) {
        long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        V.push_back(line(x1, y1, x2, y2));
    }

    for(long long i=0;i<n-1;i++) {
        for(long long j=i+1;j<n;j++) {
            if (find(i) == find(j)) continue;
            if (overlap(V[i], V[j])) {
                merge(i, j);
            }
        }
    }

    long long res[3001]={}, M = 0, cnt=0;
    for(long long i=0;i<n;i++) {
        res[find(i)] += 1;
    }
    for(long long i=0;i<n;i++) {
        // cout << find(i) << '\n';
        if (res[i] != 0) cnt++;
        M = max(res[i], M);
    }
    // cout << '\n';

    cout << cnt << '\n';
    cout << M;
}